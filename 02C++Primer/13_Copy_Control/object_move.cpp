#include <iostream>
#include <utility>

int main(){
    int &&rr1 = 42;
    //变量是左值，我们不能将一个右值引用绑定到一左值上，即使这个左值是一个右值引用类型也不行
    //int &&rr2 = rr1;

    //move函数， 返回给定对象得右值引用 
    int &&rr2 = std::move(rr1); 
    
    int f();
    int &&rr3 = f();
}   