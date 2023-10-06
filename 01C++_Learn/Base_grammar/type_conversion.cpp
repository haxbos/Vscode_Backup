#include <iostream>
using namespace std;

/*
C++ 中的4中类型转换
const_cast: 去除一个指向常量对象的指针或引用的常量属性
static_cast: 提供编译器认为安全的类型转换(没有任何联系的类型之间的转换就被否定)
reinterpret_cast: 类似于C风格的强制类型转换
dymanic_cast: 主要用在继承结构中，可以支持 RTTI 类型识别的上下转换，一般是以上转下（即父类转子类）
*/

void test_const_cast(){
    const int a = 10;

    // int *p1 = (int*) &a;
    // int *p2 = const_cast<int*>(&a);

    //const_cast只能调节类型限定符，不能更改基础类型
    //所以当想要使用const_cast进行类型转换，更改类型时，会报错，而C的类型转换不会。
    // double *p3 = (double*) &a;
    // double *p4 = const_cast<double*>(&a); //error

    //const_cast<const_cast 中的类型必须是指针、引用或指向对象类型成员的指针，如：int* , int&>
    //int p5 = const_cast<int> a;   //error
}

void test_static_cast(){
    //int *p = nullptr;
    //double *p2 = static_cast<double*>(p);   //error , double 和 int之间没有联系
    //char* p3 = static_cast<char*>(p);

    int a = 10;
    cout << a << endl;
    char a2 = static_cast<char>(a);
    cout << a2 << endl;
}

void test_reinterpret_cast(){
    int num = 1;
    int *p = &num;
    double *p2 = reinterpret_cast<double*>(p);   //error , double 和 int之间没有联系
    char* p3 = reinterpret_cast<char*>(p);

    cout << "*P = " << *p << endl;
    cout << "*p2 = " << *p2 << endl;
    cout << "*p3 = " << *p3 << endl;
}

class Base{
public:
    virtual void func(){ cout << "Base::func()" << endl;}
};

class Derivel1 : public Base{
public:
    void func() override {
        cout << "Derivel1::func()" << endl;
    }
};

class Derivel2 : public Base{
public:
    void func() override {
        cout << "Derivel2::func()" << endl;
    }
    void Derivel02func(){
        cout << "Derivel02func()" <<endl;
    }
};

void showFunc(Base* p){
    p->func();
}

void showFunc2(Base* p){
    //dynamic_cast会检查p指针是否指向一个Derivel2类型的对象；p-> vfptr -> vftable RTTI信息
    //如果是，则转换成功,返回Derivel2对象的地址；如果不是，则返回nullptr

    Derivel2* d2 = dynamic_cast<Derivel2*>(p);
    if(d2 != nullptr){
        d2->Derivel02func();
    }
    else{
        p->func();
    }
}

void test_dynamic_cast(){
    Derivel1 d1;
    Derivel2 d2;
    Base b1;
    showFunc(&b1);
    showFunc(&d1);
    showFunc(&d2);
    cout << "====================" << endl;
    showFunc2(&b1);
    showFunc2(&d1);
    showFunc2(&d2);
}

int main(){
    //test_const_cast();
    //test_static_cast();
    //test_reinterpret_cast();
    test_dynamic_cast();
}