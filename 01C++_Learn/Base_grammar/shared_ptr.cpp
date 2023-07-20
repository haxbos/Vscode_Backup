#include <iostream>
#include <memory>
using namespace std;

class A;
class B;

class A{
public:
    A(){cout << "A()" << endl;}
    ~A(){ cout << "~A()" << endl; }
    //shared_ptr<B> ptra;
    weak_ptr<B> ptra;
};

class B{
public:
    B(){cout << "B()" << endl;}
    ~B(){ cout << "~B()" << endl; }
    //shared_ptr<A> ptrb;
    weak_ptr<A> ptrb;
};

void test(){
    shared_ptr<A> pa (new A());
    shared_ptr<B> pb (new B());
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
}

//交叉引用，导致对象无法被析构
//所以：定义对象的地方，使用强智能指针(shared_ptr)；引用对象，使用弱智能指针(weak_ptr)；
void test2(){
    shared_ptr<A> pa (new A());
    shared_ptr<B> pb (new B());
    pa->ptra = pb;
    pb->ptrb = pa;
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
}

int main(){
    test();
    cout << "---------------------------" << endl;
    test2();
}