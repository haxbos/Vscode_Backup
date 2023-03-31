#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size]){
    return size;
}

int main(){
    string s[] = {"sss"};
    cout << getSize(s) << endl;

    char c[] = "s";
    //输出为2，因为字符数组末尾有一个'\0'
    cout << getSize(c) << endl;

    return 0;
}