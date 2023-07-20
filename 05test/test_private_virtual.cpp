#include <iostream>

class Base {
private:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() {  // 试图重新定义基类中的私有虚函数
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    //basePtr->foo();  // 输出 Base::foo()

    delete basePtr;
    return 0;
}