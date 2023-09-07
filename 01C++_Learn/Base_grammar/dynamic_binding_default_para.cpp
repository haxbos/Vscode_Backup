#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Base{
public:
    Base(){
        cout << "Base()" << endl;
        clear();
    }
    void clear(){ memset(this, 0, sizeof(*this)); }
    virtual void show(int i = 10) { cout << "Base::show(int)" << endl; }
    virtual void show2() {cout << "Base::show2()" << endl; }
};

class Derive : public Base{
public:
    void show(int i = 20) override { cout << i << " Derive::show(int)" << endl; }
private:
    void show2() {cout << "Derive::show2()" << endl; }
};

void test(){
    Base *p = new Derive();
    p->show();
    delete p;
}

void test2(){
    Base *p = new Derive();
    p->show2();
    delete p;
}

void test3(){
    Base *p = new Base();
    p->show2(); //动态绑定
    delete p;

    Base *p2 = new Derive();
    p2->show2(); //动态绑定
    delete p2;
}

void test4(){
    Base p =  Derive();
    p.show2();
}
int main(){
    //test();
    //test2();
    //test3();
    test4();
}