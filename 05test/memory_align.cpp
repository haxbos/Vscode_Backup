#include <iostream>
using namespace std;

struct Test{
    char ch;
    short st;
    double db;
};

struct Test2{
    char ch;
    int val;
    short st;
    double db;
};

int main(){
    cout << sizeof(Test) << endl;
    cout << alignof(Test) << endl;
    cout << sizeof(Test2) << endl;
    cout << alignof(Test2) << endl;
}