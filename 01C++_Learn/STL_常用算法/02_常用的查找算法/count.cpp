#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include<algorithm>

/*  统计元素个数
count(iterator beg,iterator end,value);
*/

//内置数据类型
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(0);
    v.push_back(20);
    v.push_back(10);
    v.push_back(0);
    v.push_back(10);
    v.push_back(30);
    int num=count(v.begin(),v.end(),10);
    cout<<num<<endl;
}

//统计自定义数据类型
class Person{
    public:
        string m_name;
        int m_age;
        Person(string name,int age){
            m_name=name;
            m_age=age;
        }

        //统计自定义数据类型的时候，需要配合重载operator==
        bool operator==(const Person & p){
            if(p.m_age==this->m_age)
                return true;
            return false;
        }
};
void test02(){
    vector<Person> v;
    Person p1("刘备",29);
    Person p2("hah",20);
    Person p3("助手",29);
    Person p4("张三",28);
    Person p5("诸葛",21);
    Person p6("管给",29);
    Person p7("二分fe",29);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);

    int num=count(v.begin(),v.end(),p1);
    cout<<"和刘备同岁的人的个数："<<num<<endl;
}
int main(){
    //test01();
    test02();
}