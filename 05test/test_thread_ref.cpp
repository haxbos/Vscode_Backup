#include <iostream>
#include <thread>

void handler1(int b)
{
    std::cout << "do handler1" << std::endl;
}
void handler2(int &b)
{
    std::cout << "do handler2" << std::endl;
}
int main()
{
    int a = 10;
    std::thread t1(handler1, a);
    t1.join();
    std::thread t2(handler1, a);
    t2.join();

    // std::thread t2(handler2, std::ref(a));  //  注意这里使用std::ref(a)即可！！！
    // t2.join();
}
