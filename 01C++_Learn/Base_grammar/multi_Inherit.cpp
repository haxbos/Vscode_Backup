#include <iostream>
using namespace std;

/*实践得出结论：
*1.多重继承中，每继承一个含虚函数的基类，派生类都会继承基类中的vptr和vtable, 并且vptr和vtable的顺序与继承的顺序一致
*2.多重继承中，如果多个基类中都拥有相同的虚函数，那么派生类如果重写了该虚函数，
*那么从基类中继承的拥有该虚函数地址的vtable中的地址都会被派生类中重写的虚函数地址覆盖
*3.多重继承中，派生类的vptr指向的是第一个基类的vtable（即与继承的第一个基类的vptr指向的vtable一致,
*所以派生类中的所有虚函数都会在第一个vptr中存在;并且不会构造中间层(non-virtual thunk)让基类的指针或引用调用派生类中的虚函数;
*4.如果基类中的构造函数是虚函数，那么vtbale中会存放有两个析构函数的指针;
vtable for Derived2:
    .quad   0
    .quad   typeinfo for Derived2
    .quad   Derived2::A()
    .quad   Base1::B()
    .quad   Base1::C()
    .quad   Derived2::~Derived2() [complete object destructor]
    .quad   Derived2::~Derived2() [deleting destructor]
    .quad   Derived2::G()
    .quad   Derived2::H()
    .quad   Derived2::I()
    .quad   -8
    .quad   typeinfo for Derived2
    .quad   Base2::D()
    .quad   Base2::E()
    .quad   non-virtual thunk to Derived2::~Derived2() [complete object destructor]
    .quad   non-virtual thunk to Derived2::~Derived2() [deleting destructor]
    .quad   -16
    .quad   typeinfo for Derived2
    .quad   Base3::F()
    .quad   non-virtual thunk to Derived2::G()
    .quad   non-virtual thunk to Derived2::~Derived2() [complete object destructor]
    .quad   non-virtual thunk to Derived2::~Derived2() [deleting destructor]
如上所示;
*/

using u64 = unsigned long long;
using func = void (*)();

class Base1{
public:
    Base1() { cout << "Base1()" << endl; }
    virtual void A() { cout << "Base1::A()" << endl; }
    virtual void B() { cout << "Base1::B()" << endl; }
    virtual void C() { cout << "Base1::C()" << endl; }
    virtual ~Base1() { cout << "~Base1()" << endl; }
};

class Base2{
public:
    Base2() { cout << "Base2()" << endl; }
    virtual void D() { cout << "Base2::D()" << endl; }
    virtual void E() { cout << "Base2::E()" << endl; }
    virtual ~Base2() { cout << "~Base2()" << endl; }
};

class Base3{
public:
    Base3() { cout << "Base3()" << endl; }
    virtual void F() { cout << "Base3::F()" << endl; }
    virtual void G() { cout << "Base3::G()" << endl; }
    virtual ~Base3() { cout << "~Base3()" << endl; }
};

class Derived:public Base2, public Base1{
public:
    Derived() { cout << "Derived()" << endl; }
    void A() override { cout << "Derived::A()" << endl; }
    void E() override { cout << "Derived::E()" << endl; }
    virtual void H() { cout << "Derived::H()" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

class Derived2:public Base1, public Base2, public Base3{
public:
    Derived2() { cout << "Derived2()" << endl; }
    void A() override { cout << "Derived::A()" << endl; }   //1,2
    //void E() override { cout << "Derived::E()" << endl; }   //2
    void G() override { cout << "Derived::G()" << endl; }   //3
    virtual void H() { cout << "Derived::H()" << endl; }
    virtual void I() { cout << "Derived::I()" << endl; }
    ~Derived2() { cout << "~Derived2()" << endl; }
};

void testSize(){
    Derived d;
    cout << "sizeof(Derived) : " << sizeof(d) << endl;
    Derived2 d2;
    cout << "sizeof(Derived2) : " << sizeof(d2) << endl;
    
    cout << "sizeof(u64) : " << sizeof(u64) << endl;
}

void testAddrDerived1(){
    Derived d;
    //vptr1 Base2
    u64 *p = (u64*)&d;
    u64 *arr1 = (u64*)*p;
    func f1 = (func)arr1[0];
    func f2 = (func)arr1[1];
    func f3 = (func)arr1[4];
    f1();
    f2();
    f3();

    cout << "=============================" << endl;
    //vptr2 Base1
    u64 *q = (u64*)((char*)p + sizeof(u64));
    u64 *arr2 = (u64*)*q;
    func f4 = (func)arr2[0];
    func f5 = (func)arr2[1];
    func f6 = (func)arr2[2];
    //func f7 = (func)arr2[3];
    f4();
    f5();
    f6();
    //f7();

    // cout << "=============================" << endl;
    // //vptr3 Derived
    // u64 *r = (u64*)((char*)q + sizeof(u64));
    // u64 *arr3 = (u64*)*r;
    // func f8 = (func)arr3[0];
    // f8();
}

void testAddrDerived2(){
    Derived2 d;
    
    //vptr1 Base1
    u64 *p = (u64*)&d;
    u64 *arr1 = (u64*)*p;
    func f1 = (func)arr1[0];
    func f2 = (func)arr1[1];
    func f3 = (func)arr1[2];
    func f5 = (func)arr1[5];
    func f6 = (func)arr1[6];
    func f7 = (func)arr1[7];
    f1();
    f2();
    f3();
    f5();
    f6();
    f7();

    cout << "=============================" << endl;
    //vptr2 Base2
    u64 *q = (u64*)((char*)p + sizeof(u64));
    u64 *arr2 = (u64*)*q;
    func f8 = (func)arr2[0];
    func f9 = (func)arr2[1];
    f8();
    f9();

    cout << "=============================" << endl;
    //vptr3 Derived
    u64 *r = (u64*)((char*)q + sizeof(u64));
    u64 *arr3 = (u64*)*r;
    func f10 = (func)arr3[0];
    func f11 = (func)arr3[1];
    f10();
    f11();
}

int main(){
    //testSize();
    //testAddrDerived1();
    testAddrDerived2();
    return 0;
}