#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <typeinfo>

int main() {
    std::vector<std::string> vec = {"Hello", "World", "!"};

    using iterator_type = decltype(vec)::iterator;
    using traits = std::iterator_traits<iterator_type>;

    std::cout << "Value type: " << typeid(traits::value_type).name() << std::endl;
    std::cout << "Pointer type: " << typeid(traits::pointer).name() << std::endl;
    std::cout << "Reference type: " << typeid(traits::reference).name() << std::endl;

    return 0;
}