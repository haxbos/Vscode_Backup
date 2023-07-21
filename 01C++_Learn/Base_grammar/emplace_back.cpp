#include <iostream>
#include <cstdlib>
#include <utility>
using std::cout,std::endl;

class Test{
public:
    Test(int a, int b) : m_a(a), m_b(b){
        cout << "Test(int a, int b) " << endl;
    }
    ~Test(){
        cout << "~Test()" << endl;
    }

    Test(Test&& rhs) noexcept {
        if (this == &rhs) return;

        this->m_a = rhs.m_a;
        this->m_b = rhs.m_b;
        // this->m_a = std::move(rhs.m_a);
        // this->m_b = std::move(rhs.m_b);
        cout << "Test(Test&& rhs) " << endl;
    }
    
    Test(const Test& rhs){
        if(this == &rhs) return;

        this->m_a = rhs.m_a;
        this->m_b = rhs.m_b;
        cout << "Test(const Test& rhs) " << endl;
    }

private:
    int m_a;
    int m_b;
};

template<typename T>
class MyAllocator{
public:
    T* allocate(size_t size){
        return (T*)malloc(size * sizeof(T));
    }

    template<typename... Types>
    void construct(T* ptr, Types&&... args){
        new (ptr) T(std::forward<Types>(args)...);
    }
};

template<typename T, typename Alloc = MyAllocator<T>>
class MyVector{
public:
    MyVector():_vec(nullptr),_size(0),idx(0){}
    void reserve(size_t size){
        _vec = allocator.allocate(size);
        _size = size;
    }

    // void push_back(const T& val){
    //     allocator.construct(_vec + idx, val);
    //     ++idx;
    // }
    // void push_back(T&& val){
    //     allocator.construct(_vec + idx, std::move(val));
    //     ++idx;
    // }
    template<typename Type>
    void push_back(Type&& val){
        allocator.construct(_vec + idx, std::forward<Type>(val));
        ++idx;
    }

    template<typename... Types>
    void emplace_back(Types&&... args){
        allocator.construct(_vec + idx, std::forward<Types>(args)...);
        ++idx;
    }
    ~MyVector(){
        delete _vec;
    }
private:
    T* _vec;
    size_t _size;
    size_t idx;
    Alloc allocator;
};

void test(){
    MyVector<Test> vec;
    Test t{10,20};
    vec.reserve(10);
    vec.push_back(t);
    cout << "==========0==========" << endl;
    vec.emplace_back(t);
    cout << "==========1==========" << endl;
    vec.push_back(Test{20,20});
    cout << "==========2==========" << endl;
    vec.emplace_back(Test{30,30});
    cout << "==========3==========" << endl; 
    //vec.push_back(22,33); //error
    vec.emplace_back(33,44);
}
int main(){
    test();
}