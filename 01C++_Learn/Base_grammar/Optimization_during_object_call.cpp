#include <iostream>
using namespace std;

class Test{
public:
    Test(){cout << "Test()" << endl; };
    Test(const int& a):m_a(a){ cout << "Test(const int&)" << endl; }
    Test(const Test& t): m_a(t.m_a) { cout << "Test(const Test&)" << endl; }
    Test& operator= (const Test& rhs){
        cout << "operator= (const Test&)" << endl;
        m_a = rhs.m_a;
        return *this;
    }
    Test(Test&& t):m_a(t.m_a){ cout <<"Test(Test &&)" << endl; }
    int getData(){ return m_a; }
    ~Test(){ cout << "~Test()" << endl; }
private:
    int m_a;
};

void test_object_call(){
    Test t1;
    Test t2(10);
    Test t3 = t2;
    cout << "----------------------" << endl;

    /*c++编译器对于对象构造的优化：用临时对象生成新对象的时候，
        临时对象就不产生了，直接构造新对象就可以了*/
    Test t4 = Test(40);     //和Test t4(40); 没有区别
    Test t5 = (Test)50;     //显示构造
    Test t6 = 60;           //隐式构造
    cout << "----------------------" << endl;

    t6 = t2;
    t6 = Test(40);  //Test(40) 显示生成临时对象 生存周期：所在语句
    t6 = 40;
    cout << "----------------------" << endl;

    //Test* p1 = &Test(80);
    const Test &ref = Test(90);
    cout << "----------------------" << endl;
}

Test getObject(Test t){
    int val = t.getData();
    //Test tmp(val);
    //return tmp; "--------------------------" << endl;
    return Test(val);
}

void test_func_call(){
    Test t1;
    Test t2;
    t2 = getObject(t1);
}

void test_func_call2(){
    Test t1;
    Test t2 = getObject(t1);
}

int main(){
    //test_object_call();

    cout << "--------------------------" << endl;

    test_func_call();

    cout << "--------------------------" << endl;

    test_func_call2();
}