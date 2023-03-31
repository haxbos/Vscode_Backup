#include <iostream>
#include <vector>
using namespace std;

class X{
public:
    X() { cout << "X()" << endl;} 
    X(const X&) {cout << "X(const &X)" << endl;}

    X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this;}
    ~X(){ cout << "~X()" << endl;}
};  

void f(const X& rx, X r){
    vector<X> vec;

    //如果不先使用reserve预留足够的空间，那么根据vector的底层原理
    //在size == capacity 的时候，vector 会寻找一个新的地址，容量一般是原来的double 
    //所以之前的元素会拷贝到新的地址，这样就会有多拷贝构造被调用
    vec.reserve(2);
    //添加到容器，采用拷贝构造函数
    vec.emplace_back(rx);
    vec.push_back(r);
    
}

int main(){

    //动态分配对象，采用默认构造函数
    X *px = new X;

    //传递参数，第一个参数为引用参数，无调用，第二个参数为非引用参数，采用拷贝构造函数
    f(*px, *px);
    delete px;
}