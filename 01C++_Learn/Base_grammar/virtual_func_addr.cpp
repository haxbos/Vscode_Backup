#include <iostream>
using namespace std;

using u64 = unsigned long long;
using func = void (*)();

class Base{
public:
    virtual void A(){ cout << "Base::A" << endl; }
    virtual void B(){ cout << "Base::B" << endl; }
    virtual void C(){ cout << "Base::C" << endl; }

private:
    int x;
    int y;
};

class Derived : public Base{
public:
    virtual void B(){ cout << "Derived::B" << endl; }
};

void test_size(){
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(int*) = " << sizeof(int*) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
}

void testFunctionAddrOfBase(){
    Base b;
    u64 *p = (u64*)&b;
    u64 *arr = (u64*)*p;
    func fa = (func)arr[0];
    func fb = (func)arr[1];
    func fc = (func)arr[2];
    fa();
    fb();
    fc();
}

void testFunctionAddrOfDerived(){
    Derived d;
    u64 *p = (u64*)&d;
    u64 *arr = (u64*)*p;
    func fa = (func)arr[0];
    func fb = (func)arr[1];
    func fc = (func)arr[2];
    fa();
    fb();
    fc();
}

void testVirtualFuncAddr(){
    Base b;
    u64 *p = (u64*)&b;
    u64 *arr = (u64*)*p;
    Derived d;
    u64 *q = (u64*)&d;
    u64 *arr2 = (u64*)*q;

    for(int i=0; i<3; i++){
        cout << "arr[" << i << "]  = " << arr[i] << endl;
        cout << "arr2[" << i << "] = " << arr2[i] << endl;
    }
}

int main(){
    //test_size();
    testFunctionAddrOfBase();
    cout << "---------------------" << endl;
    testFunctionAddrOfDerived();
    cout << "---------------------" << endl;
    testVirtualFuncAddr();
    return 0;
}