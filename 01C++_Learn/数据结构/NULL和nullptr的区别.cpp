#include<iostream>
using namespace std;

void func(void* i){
    cout<<"func1被调用"<<endl;
}

void func(int i){
    cout<<"func2被调用"<<endl;
}
int main(){
    func(NULL); //在C++中，NULL==> int 0    ,C++是强类型语言，不允许void *隐式转化为其他类型的指针，所以NULL==0，C语言中可以
    func(nullptr);  //nullptr==>(void *)0  ，在C++中，任何情况都代表空指针
    return 0;
}