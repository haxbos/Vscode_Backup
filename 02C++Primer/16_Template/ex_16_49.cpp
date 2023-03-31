#include <iostream>
#include <memory>
#include <sstream>

template <typename T> void f(T)
{
    std::cout << "f(T)\n";
}

template <typename T> void f(const T*)
{
    std::cout << "f(const T*)\n";
}
template <typename T> void g(T)
{
    std::cout << "template <typename T> void g(T)\n";
}
template <typename T> void g(T*)
{
    std::cout << "template <typename T> void g(T*)\n";
}



int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);    //template <typename T> void g(T ); --is called
    g(p);     //template <typename T> void g(T*); --is called
    g(ci);      //template <typename T> void g(T)   --is called
    g(p2);      //template <typename T> void g(T*)    --is called
    f(42);    //f(T)
    f(p);     //f(T)
    f(ci);    //f(T)
    f(p2);      //f(const T*)
}