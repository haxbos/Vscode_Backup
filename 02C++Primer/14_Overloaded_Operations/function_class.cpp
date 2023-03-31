#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//函数类
class AbsInt{
public:
    int operator() (int val){
        return val >= 0 ? val : -val;
    }
};

void test01(){
    AbsInt absObj;
    cout << absObj(-12) << endl;
}

//含有状态的函数类
class PrintString{
public:
    PrintString(ostream &o = cout, char c = ' '): 
        os(o), step(c){}
    void operator()(const string &s) const{
        os << s << step;
    }
private:
    ostream &os;
    char step;
};

void test02(){
    string s = "hello,world";
    PrintString ps;
    ps(s);

    cout << endl;

    PrintString ps2(cerr,'\n');
    ps2("overload , hello_world");
}

void test03(){
    vector<string> vec={"hi","world","test","vector"};
    for_each(vec.begin(),vec.end(),PrintString(cerr,'\n'));
}

int main(){
    //test01();
    //test02();
    test03();
    return 0;
}