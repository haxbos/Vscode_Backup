#include <iostream>
using namespace std;

using u64 = unsigned long long;
using func = void (*)();

class A{
public:
    A() { cout << "A()" << endl; }
    virtual void A1() { cout << "A::A1()" << endl; }
    virtual void B1() { cout << "A::B1()" << endl; }
    virtual void C1() { cout << "A::C1()" << endl; }
    virtual ~A() { cout << "~A()" << endl; }
};

class B: virtual public A{
public:
    B() { cout << "B()" << endl; }
    virtual void D2() { cout << "B::D2()" << endl; }
    virtual void E2() { cout << "B::E2()" << endl; }
    virtual ~B() { cout << "~B()" << endl; }
};

class C: virtual public A{
public:
    C() { cout << "C()" << endl; }
    virtual void F3() { cout << "C::F3()" << endl; }
    virtual void G3() { cout << "C::G3()" << endl; }
    virtual ~C() { cout << "~C()" << endl; }
};

class Derived: virtual public B, virtual public C{
public:
    Derived() { cout << "Derived()" << endl; }
    void A1() override { cout << "Derived::A1()" << endl; }
    
    virtual void H() { cout << "Derived::H()" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

void testSize(){
    Derived d;
    cout << "sizeof(Derived) : " << sizeof(d) << endl;
    cout << "sizeof(u64) : " << sizeof(u64) << endl;
}

int main(){
    testSize();
    return 0;
}