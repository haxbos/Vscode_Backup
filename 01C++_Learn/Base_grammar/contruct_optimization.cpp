#include <iostream>
using namespace std;

class Test{
public:
    Test(int a = 10) : m_a(a){
        cout << "Test()" << endl;
    }

    Test(const Test& t): m_a(t.m_a){
        cout << "Test(const &)" << endl;
    }

    Test& operator=(const Test& rhs){
        cout << "operator=()" << endl;
        m_a = rhs.m_a;
        return *this;
    }

    ~Test(){
        cout << "~Test()" << endl;
    }
private:
    int m_a;
};


int main(){
    Test t1;
    Test t2(t1);
    Test t3 = t1;

    //C++编译器对于构造函数的优化：如果用临时对象生成新对象时，临时对象就不产生了
    //直接构造新对象就可以了，所以 4、5没区别
    Test t4 = Test(20);
    Test t5(30);

    return 0;
}
