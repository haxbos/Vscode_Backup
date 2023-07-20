#include <iostream>
using namespace std;

int *func(){
    int data = 10;
    return &data;
}

int main(){
    int *p = func();
    cout << *p << endl;
}