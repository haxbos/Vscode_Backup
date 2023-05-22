#include <iostream>
using namespace std;

class Bad{
public:
    Bad(){ cout << "Bad constructor" << endl; }
    ~Bad(){ cout << "Bad destructor" << endl; }
};

class FOO{
public:
    FOO(){ cout << "FOO constructor" << endl; }
    FOO(int) { cout << "FOO constructor with int" << endl; throw  Bad();}
    //FOO(int) { cout << "FOO constructor with int" << endl;}

    //1: 一般的opertor new() 的重载 
    void* operator new(size_t size){
        cout << "FOO::operator new" << endl;
        return malloc(size);
    }

    //2: 标准库中已经提供的的placement new() 的重载 
    void *operator new(size_t size, void *start){
        cout << "FOO::operator new with start" << endl;
        return start;
    }

    //3: placement new() 的重载
    void *operator new(size_t size, long extra){
        cout << "FOO::operator new with extra" << endl;
        return malloc(size + extra);
    }

    //4: placement new() 的重载
    void *operator new(size_t size, long extra, char init){
        cout << "FOO::operator new with extra and init" << endl;
        return malloc(size + extra);
    }

    //5: error, 分配的第一个参数必须是size_t
    // void *operator new(long extar, char init){
    //     cout << "FOO::operator new with extra and init" << endl;
    //     return malloc(extar);
    // }

    // //1: 一般的operator delete() 的重载
    // void operator delete(void *, size_t){
    //     cout << "FOO::operator delete" << endl;
    // }

    // //2: 对于上面的2，下同
    // void operator delete(void *, void *){
    //     cout << "FOO::operator delete with start" << endl;
    // }

    // //3
    // void operator delete(void *, long){
    //     cout << "FOO::operator delete with extra" << endl;
    // }

    // //4
    // void operator delete(void *, long, char){
    //     cout << "FOO::operator delete with extra and init" << endl;
    // }

private:
    int m_i;
};

int main(){
    FOO start;
    FOO *p1 = new FOO;
    FOO *p2 = new(&start) FOO;
    FOO *p3 = new(100) FOO;
    FOO *p4 = new(100, 'a') FOO;
    FOO *p5 = new(100) FOO(1);
    FOO *p6 = new(100, 'a') FOO(1);
    FOO *p7 = new(&start) FOO(1);
    FOO *p8 = new FOO(1);
}