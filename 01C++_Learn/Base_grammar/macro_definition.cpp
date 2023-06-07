#include <iostream>

// 定义可变参数宏
#define PRINT_VALUES(...) \
    do { \
        std::cout << "Values: "; \
        printValues(__VA_ARGS__); \
        std::cout << std::endl; \
    } while(0)

// 辅助函数，用于打印参数值
template<typename T>
void printValues(T value) {
    std::cout << value << " !";
}

template<typename T, typename... Args>
void printValues(T value, Args... args) {
    std::cout << value << " ";
    printValues(args...);
}

int main() {
    int a = 10;
    double b = 3.14;
    std::string c = "Hello";

    // 使用可变参数宏打印多个值
    PRINT_VALUES(a, b, c);

    return 0;
}