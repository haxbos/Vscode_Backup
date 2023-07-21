#include <iostream>
#include <typeinfo>
using namespace std;

class Base{
public:
    Base(){ cout << "Base()" << endl; }
    Base(int) {cout << "Base(int)" << endl; }
    virtual void show() { cout << "Base::show()" << endl; }
    void show(int) {cout << "Base::show(int)" << endl; }
    ~Base(){ cout << "~Base()" << endl; }
    //virtual ~Base(){ cout << "~Base()" << endl; }
private:
    int m_a;
};

class Derive : public Base{
public:
    Derive() { cout << "Derive()" << endl; }
    Derive(int) { cout << "Derive(int)" << endl; }
    void show() override { cout << "Derive::show()" << endl; }
    void show(int) {cout <<"Derive::show(int)" << endl; }
    ~Derive() { cout << "~Derive()" << endl; }
private:
    int m_b;
};



void test(){
    Derive d1;
    Base* bp = &d1; 
    bp->show(); //动态绑定 ，因为 Base::show为virtual虚函数，所以需要在运行时确定
    cout << "*bp : " << typeid(*bp).name() << endl;
    cout << "bp : " << typeid(bp).name() << endl;

    cout << "================================" << endl;

    Derive d2;
    Base* bp2 = &d2; 
    bp2->show(10); //静态绑定， 因为Base::show(int)不是虚函数，所以可以在编译时确定
    cout << "*bp : " << typeid(*bp2).name() << endl;
    cout << "bp : " << typeid(bp2).name() << endl;
}

void test2(){
    Base* bp = new Derive(10);
    bp->show();
    delete bp;
}

void test3(){
    Base b;
    Derive d;
    //对象本身调用虚函数，是静态绑定
    b.show();
    d.show();
    
    //动态绑定只有通过指针或引用调用虚函数时才会发生
    Base *bp1 = &b;
    bp1->show();
    Base *bp2 = &d;
    bp2->show();

    Base &rb1 = b;
    rb1.show();
    Base &rb2 = d;
    rb2.show();
}

int main(){
    test();
    //test2();
    //test3();
}