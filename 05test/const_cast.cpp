#include <iostream>
using namespace std;

class Person{
public:
    Person(string name, int age): m_name(name),m_age(age){cout << "Person(string,int)" << endl; }
    const string& getName() const { return m_name; }
    const int& getAge() const { return m_age; }
    ~Person(){cout << "~Person()" << endl; }
private:
    string m_name;
    int m_age;
};

void test(){
    Person p("tom",18);
    const int* oldAge = &(p.getAge());
    int* newAge = const_cast<int*>(oldAge);
    *newAge = 20;
    cout <<"p.getAge() : " << p.getAge() << endl;
    cout <<"*oldAge : " << *oldAge << endl;
    cout <<"*newAge : " << *newAge << endl;
}

int main(){
    test();
}