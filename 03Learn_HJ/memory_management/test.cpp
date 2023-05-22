#include <iostream>
#include <memory>
using namespace std;

void test_alloctor(){
    //因为下面的函数都是 non-static, 所以一定要通过对象来调用
    int *p4 = allocator<int>().allocate(3);
    allocator<int>().construct(p4, 5);
    cout << "p4: " << *p4 << endl;
    allocator<int>().deallocate(p4, 3);
}

void test_Dtor(){
    string *p = new string;
    cout << "p: " << p << endl;
    //! p->string::string("hello");
                        // error: 'class std::__cxx11::basic_string<char>' has no member named 'string'
    cout << "p: " << p << endl;
    p->~string();
    cout << "p: " << p << endl;
}

class A{
public:
    int id;
    A(): id(0) { cout << "default ctor.this = " << this << " id = " << id << endl; }
    A(int i): id(i) { cout << "ctor.this = " << this << " id = " << id << endl; }
    ~A() { cout << "dtor.this = " << this << " id = " << id << endl; }
};

void test_array_new_delete(){
    A *buf = new A[3];

    A *tmp = buf;

    cout << "buf = " << buf << " tmp = " << tmp << endl;

    for(int i=0; i<3; i++){
        new(tmp++) A(i);
    }

    cout << "buf = " << buf << " tmp = " << tmp << endl;
    delete[] buf;
}

void test_array_new_delete2(){
    int *p1 = new int[10];
    int *p2 = p1;

    for(int i=0; i<10; i++){
        new(p2++) int(i);
    }

    int *p3 = p1;
    for(int i=0; i<10; i++){
        cout << *p3++ << endl;
    }
    
    //int *p4 = p1;
    delete p1;
    for(int i=9; i>=0; --i){
        cout << *(--p3) << endl;
    }
    
}

int main(){
    //test_alloctor();
    //test_Dtor();
    //test_array_new_delete();
    test_array_new_delete2();
}
