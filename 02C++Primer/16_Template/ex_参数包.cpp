#include <iostream>
#include <string>
#include <bitset>
using namespace std;

template<typename T, typename... Args>
void foo(T t, Args... args){
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
}

int main(){
    string s = "hi";
    //foo(7.5,string("hello"),bitset<16>(377),42);
    foo(7.5,string("hello"),bitset<16>(377), string("hiwor"));
}