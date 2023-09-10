#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
    Test() { cout << "Test()" << endl; }
    void show() { cout << "show()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
};

int main(){
    Test *t = new Test();
    unique_ptr<Test> up(t);
    cout << "up ";
    up->show();

    unique_ptr<Test> up2(new Test());
    cout << "up2 ";
    up2->show();

    unique_ptr<Test> up3(t);
    cout << "up3 ";
    up3->show();
    return 0;
}