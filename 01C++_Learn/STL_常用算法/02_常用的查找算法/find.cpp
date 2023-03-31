#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<string>

/*查找指定元素，找到了，返回该元素的迭代器，没找到，则返回结束迭代器end()  */

/*
find(iterator beg,iterator end,value);
*/

//查找内置数据类型
void test01(){
    vector<int> v;
    for(int i=6;i<15;i++)
        v.push_back(i);
    v.push_back(5);

    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it!=v.end())
        cout<<*it<<endl;
    else
        cout<<"没找到"<<endl;
}

class Person{
    public:
        string m_name;
        int m_age;
        Person(string name,int age){
            m_name=name;
            m_age=age;
        }

        //重载== ，让底层find知道如何对比Person数据类型
        bool operator==(const Person& p){
            if(this->m_name==p.m_name && this->m_age==p.m_age)
                return true;
            return false;
        }
};
//查找自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("张三",2);
    Person p2("qqq",4);
    Person p3("ccc",88);
    Person p4("ww",223);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it=find(v.begin(),v.end(),p2);
    if(it==v.end())
        cout<<"没找到"<<endl;
    else
        cout<<p2.m_name<<"\t"<<p2.m_age<<endl;

}

int main(){
    //test01();
    test02();
}