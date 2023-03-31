#include <iostream>
#include <vector>
using namespace std;

void double_and_insert(std::vector<int>& v, int some_val)
{
    auto mid = [&]{ return v.begin() + v.size() / 2; };

    //不能直接使用指向中间的迭代器，因为在进行insert之后，该元素之后的迭代器都会失效
    //auto mid = v.begin() + v.size()/2;
        
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    for (auto i : v) 
        std::cout << i << " ";
    cout << endl;
    double_and_insert(v, 1);

    for (auto i : v) 
        std::cout << i << " ";
}