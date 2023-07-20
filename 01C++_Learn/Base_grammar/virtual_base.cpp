#include <iostream>
using namespace std;

class Base{
public:
    virtual void show(){cout << "Base::show()" << endl;}
    void operator delete(void* ptr){
        cout << "operator delete *ptr : " << ptr << endl;
        free(ptr);
    }
private:
    int m_a;
};

class Derive : virtual public Base{
public:
    void show() override{ cout << "Derive::show()" << endl; }
    void *operator new(size_t size){
        void *p = (void *)malloc(size);
        cout << "operator new() : " << p << endl;
        return p;
        
    }
private:
    int m_b;
};

void test(){
    //基类指针指向派生类对象，永远指向的是派生类中基类部分数据的起始地址
    Base *b = new Derive();
    cout << "Base *b : " << b << endl;
    b->show();
    delete b;
}

int main(){
    //test();
    cout << "sizeof(int*) : " << sizeof(int*) << endl;
    Derive d;
    cout << "sizeof(Derive) : " << sizeof(d) << endl;
}
