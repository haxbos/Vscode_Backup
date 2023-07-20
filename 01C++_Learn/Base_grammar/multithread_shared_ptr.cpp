#include <iostream>
#include <memory>
#include <thread>
using namespace std;

class A{
public:
    A(){ cout << "A()" << endl; }
    ~A(){ cout << "~()" << endl; }
    void test() { cout << "A is very good object" << endl; }
};

void handler(weak_ptr<A> p){
    shared_ptr ps = p.lock();
    if(ps != nullptr){
        ps->test();
    }
    else{
        cout << "A object already Destruct" << endl;
    }
}

int main(){
    shared_ptr<A> pa( new A());
    thread t1(handler, weak_ptr<A>(pa));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    t1.detach();
}