#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    Animal(string name): m_name(name) {}
    virtual void bark() = 0;
protected:
    string m_name;
};

class Cat : public Animal{
public:
    Cat(string name):Animal(name){}
    void bark() override { cout << m_name << " bark: miao miao" << endl; }
};

class Dog : public Animal{
public:
    Dog(string name): Animal(name){}
    void bark() override { cout << m_name << " bark: wang wang" << endl; }
};

void test(){
    Animal *cat = new Cat("coffee cat");
    Animal *dog = new Dog("wang cai");

    int *p1 = (int*) cat;
    int *p2 = (int*) dog;

    //这两个对象的前4个字节是 vfptr
    int temp = p1[0];
    p1[0] = p2[0];      // cat --> vfptr --> Dog::vftable
    p2[0] = temp;       // dog --> vfptr --> Cat::vftable

    cat->bark();    // cat --> wang wang
    dog->bark();    // dog --> miao miaox

    delete cat;
    delete dog;
}

int main(){
    test();
}
