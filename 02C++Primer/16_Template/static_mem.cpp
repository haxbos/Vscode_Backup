#include <iostream>
using namespace std;

template <typename T>
class Foo{
public:
    static size_t count() {return ctr;}
private:
    static size_t ctr;
};

template <typename T>
size_t Foo<T>::ctr = 0;

int main(){
    Foo<int> fi;
    //auto ct = Foo<int>::count();
    auto ct = fi.count();
    cout << ct << endl;
    return 0;
}