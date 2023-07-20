#include <iostream>
using namespace std;

class Test{
public:
    explicit Test(int a = 10) :m_a(a){cout << m_a << " Test(int)" << endl;}
    ~Test(){cout << "~Test()" << endl; }
public:
    int m_a;
};

void doSomeWork(const Test& t){
    cout << "doSomeWork" << endl;
}

int main(){
    doSomeWork(Test(15));
    doSomeWork(static_cast<Test>(20));
}