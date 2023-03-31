#include <iostream>
using namespace std;

int main(){
    int id = 42;
    
    //mutable 表示 里面的值是可变的，如果不加，则 ++id 是错误的
    auto f = [id]() mutable{    
        cout << "id = " << id << endl;
        ++id;
    };

    f();
    f();
    f();
    cout << "id = " << id << endl;
}