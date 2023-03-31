#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <exception>
#include <fstream>
using namespace std;

class StrBlobPtr;

class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> li):data(make_shared<vector<string>>(li)){}

    size_type size () const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string &str) {data->push_back(str);}

    void pop_back();
    string front();
    string back();

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &mag) const;
};

void StrBlob::check(size_type i, const string &msg) const{
    if(i >= data->size()){
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back(){
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

string StrBlob::front(){
    check(0,"front on empty StrBlob");
    return data->front();
}

string StrBlob::back(){
    check(0,"back on empty StrBlob");
    return data->back();
}

class StrBlobPtr{
public:
    StrBlobPtr() : curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz){}

    bool operator!=(const StrBlobPtr &p) {return p.curr != curr;}
    string &deref() const{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr &incr(){
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret) throw runtime_error("unbound StrBlobPtr");
        if(i >= ret->size()) throw out_of_range(msg);
        return ret;
    }

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

//这两个函数必须定义在 StrBlobPtr类之后，或者另起一个文件定义
//因为该函数使用了 在StrBlob 中定义，而且使用了 StrBlobPtr 的构造函数，所以，必须在 StrBlobPtr 类之后定义
StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this,data->size());
}

void test_shared_ptr(){
    StrBlob vec1({"haha","world"});
    vec1.push_back("xixi");
    cout << "vec1 = " << vec1.size() << endl;

    for(int i=1; i<=4; ++i){
        vec1.pop_back();
        cout << vec1.size() << endl;
    }

    StrBlob vec2 = vec1;
    vec2.push_back("hello");
    cout << "vec2 = " << vec2.size() << endl;
    cout << "vec1 = " << vec2.size() << endl;
}

void weak_ptr_fileRd(){
    ifstream ifs("book.txt");
    StrBlob blob;
    for(string str; getline(ifs,str);){
        blob.push_back(str);
    }

    for(StrBlobPtr pbeg(blob.begin()),pend(blob.end()); pbeg != pend; pbeg.incr()){
        cout << pbeg.deref() << endl;
    }
}

int main(){
    //test_shared_ptr();
    weak_ptr_fileRd();
}