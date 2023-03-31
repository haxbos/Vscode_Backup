#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T> string debug_rep(const T& t){
    ostringstream ret;
    ret << t;
    return ret.str();
}

// template<typename T>
// string debug_rep(T *p){
//     ostringstream ret;
//     ret<< "pointer: " << p;
//     if(p)
//         ret << " " << debug_rep(*p);
//     else
//         ret << " null pointer";
    
//     return ret.str();
// }

int main(){
    string s = "hi";
    
    //cout <<debug_rep(s) <<endl; //模板1被调用

    //两个模板都可行，但是模板2更加特化，更加合适
    cout <<debug_rep(&s) <<endl; //模板2被调用
}