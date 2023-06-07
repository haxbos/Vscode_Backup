#include <iostream>
using namespace std;

void test(int *p){
    cout << "test p: " << p << endl;
    cout << "test *p: " << *p << endl;

    // int a = 1;
    // p = &a;
    // cout << "test &a: " << &a << endl; // "test &a: 0x7ffeeb0b0a9c

    *p = 33;
    cout << "test p: " << p << endl;
    cout << "test *p: " << *p << endl;
}

void test2(int &p){
    cout << "test2 p: " << p << endl;
    cout << "test2 &p: " << &p << endl;

    int a = 1;
    p = a;
    cout << "test2 p: " << p << endl;
    cout << "test2 &p: " << &p << endl;
}

int main(){
    int b = 2;
    int *p = &b;
    cout << "&b: " << &b << endl;
    cout << "p1: " << p << endl;
    cout << "*p1: " << *p << endl;

    test(p);
    cout << "b: " << b << endl; // "b: 33"
    cout << "p2: " << p << endl;
    cout << "*p2: " << *p << endl;
    return 0;
}