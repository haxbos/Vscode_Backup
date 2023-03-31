#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class TextQuery;
class QueryResult;

class Query_base{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    //eval 返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0;

    //rep 是表示查询的一个string
    virtual string rep() const = 0;
};

class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&); //构建一个新的WordQuery

    //接口函数：调用对应的Query_base操作
    QueryResult eval(const TextQuery& t) const{
        return q->eval(t);}
    
    string rep() const { 
        cout << "Query::rep" << endl;
        return q->rep(); 
    }

private:
    Query(shared_ptr<Query_base> query): q(query) { }
    shared_ptr<Query_base> q;
};

ostream& operator<<(ostream& os, const Query& query){
    //Query::rep通过它的Query_base指针对rep进行了虚调用
    return os << query.rep();
}

class WordQuery: public Query_base{
private:
    friend class Query; //Query使用WordQuery构造函数
    WordQuery(const string& s): query_word(s) { }

    QueryResult eval (const TextQuery& t) const{
        return t.query(query_word);}
    
    string rep() const { 
        cout << "WordQuery::rep" << endl;
        return query_word; 
    }

    string query_word;  //要查找的单词
};

class NotQuery: public Query_base{
private:
    friend Query operator~(const Query&);

    NotQuery(const Query& q) : query(q) { }

    string rep() const { 
        cout << "NotQuery::rep" << endl;
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const;

    Query query;
};

inline
Query operator~(const Query &operand){
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base{
protected:
    BinaryQuery(const Query& l, const Query& r, string s):
        lhs(l), rhs(r), opSym(s) {}
    
    //抽象类：BinaryQuery不定义eval
    string rep () const {
        cout << "BinaryQuery::rep" << endl;
        return "(" + lhs.rep() + " " 
                   + opSym + " " 
                   + rhs.rep() + ")"; 
    }

    Query lhs, rhs; 
    string opSym;   //运算符的名字
};

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "&") { }
    
    QueryResult eval(const TextQuery&) const;
};

inline
Query operator&(const Query& lhs, const Query& rhs){
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs)); 
}

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "|") { }

    QueryResult eval(const TextQuery&) const;
};

inline
Query operator|(const Query&lhs, const Query& rhs){
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input_file;    //输入文件
    //每个单词到它所在的行号的集合的映射
    map<string,shared_ptr<set<line_no>>> result;
};

TextQuery::TextQuery(ifstream& ifs) : input_file(new vector<string>){
    //line_num是行号，line是当前行的内容
    line_no line_num{0};
    //getline 从输入流中读取一行
    for(string line; getline(ifs, line); ++line_num){
        input_file->push_back(line);
        istringstream line_stream(line);
        for(string text, word; line_stream >> text; word.clear()){
            //避免标点符号干扰搜索
            //q:back_inserter(word)
            //a:back_inserter(word)返回一个back_insert_iterator，它的操作是将元素插入到word的尾部
            //remove_copy_if函数
            remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);

            //使用引用避免拷贝
            //result[word]是一个set<line_no>的shared_ptr
            auto& lines = result[word];
            if(!lines)  //第一次遇到这个单词
            
                lines.reset(new set<line_no>);
            //将此行号插入set中
            lines->insert(line_num);
        }
    }
}

class QueryResult{
public:
    friend ostream& print(ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::line_no>> p, 
                shared_ptr<vector<string>> f):
        word(s), lines(p), input_file(f) { }
private:
    string word;
    shared_ptr<set<TextQuery::line_no>> lines; //出现的行号
    shared_ptr<vector<string>> input_file;    //输入文件
};

QueryResult TextQuery::query(const string& str) const{
    //如果未找到str，我们将返回一个指向此set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto found = result.find(str);
    if(found == result.end()) return QueryResult(str, nodata, input_file);
    else return QueryResult(str, found->second, input_file);
}

ostream& print(ostream& os, const QueryResult& qr){
    os << qr.word << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 1 ? "times" : "time") << endl;
    
    for(auto num : *qr.lines)   //对set中每个单词打印出现的行号
        os << "\t(line " << num + 1 << ") "
        //q:qr.input_file->at(num)和q:*(qr.input_file->begin() + num)有什么区别？
        //a:at()和begin()都是返回迭代器，但是at()是随机访问迭代器，begin()是输入迭代器
            << *(qr.input_file->begin() + num) << endl; //行号从0开始
}

QueryResult
OrQuery::eval (const TextQuery& text) const{
    auto right = rhs.eval(text), left = lhs.eval(text);
    //将左侧运算对象所得的行号拷贝到结果set中
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    //插入右侧运算对象所得的行号
    ret_lines->insert(right.begin(), right.end());
    //返回一个新的QueryResult，表示lhs和rhs的并集
    return QueryResult(rep(), ret_lines, left.get_file());
}