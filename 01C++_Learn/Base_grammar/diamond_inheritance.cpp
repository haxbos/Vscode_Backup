#include <iostream>
using namespace std;

class A{
public:
    A(int data) : m_a(data){ cout << "A()" << endl; }
    ~A(){ cout << "~A()" << endl; }
private:
    int m_a;
};

class B : virtual public A{
public:
    B(int data) : A(data), m_b(data) { cout << "B()" << endl; }
    ~B(){ cout << "~B()" << endl; }
private:
    int m_b;
};

class C : virtual public A{
public:
    C(int data) : A(data), m_c(data) { cout << "C()" << endl; }
    ~C(){ cout << "~C()" << endl; }
private:
    int m_c;
};

class D : public B, public C{
public:
    D(int data) : A(data), B(data), C(data), m_d(data) { cout << "D()" << endl; }
    ~D(){ cout << "~D()" << endl; }
private:
    int m_d;
};

void test(){
    D d(10);
}

int main(){
    test();
}