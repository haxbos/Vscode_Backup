#include <iostream>

int main() {
    int x = 10;

    // mutable关键字，表示可以修改捕获的变量的副本
    // 如果不加mutable关键字，就不能修改捕获的变量的副本
    auto f = [x]() mutable{
        x = 20; // 修改了捕获的变量的副本
        std::cout << "x inside lambda: " << x << std::endl;
    };
    f();
    std::cout << "x outside lambda: " << x << std::endl;
    return 0;
}
