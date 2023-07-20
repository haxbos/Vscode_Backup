#include <iostream>
using namespace std;

int main(){
    //禁止一个常量字符串转换为一个 char*
    //char *p = "helloworld";
    const char* p = "helloworld";
    //*p = 'a';
    cout << *p << endl;
}