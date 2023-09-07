#include <iostream>
using namespace std;

class BaseMember{
public:
    BaseMember() { cout << "BaseMember()" << endl; }
    ~BaseMember() { cout << "~BaseMember()" << endl; }
};

class Base{
public:
    Base():m() { cout << "Base()" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
private:
    BaseMember m;
};

class DerivedMember{
public:
    DerivedMember() { cout << "DerivedMember()" << endl; }
    ~DerivedMember() { cout << "~DerivedMember()" << endl; }
};

class Derived:public Base{
public:
    Derived():dm() { cout << "Derived()" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
private:
    DerivedMember dm;
};

void test(){
    Base *b = new Derived();
    delete b;
}

int main(){
    test();
    return 0;
}