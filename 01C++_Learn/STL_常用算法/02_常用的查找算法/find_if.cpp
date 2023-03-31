#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<string>

/*  按条件查找元素
find(iterator beg,iterator end,_pred);
//按值查找，找到了，返回指定元素的迭代器，没找到则返回结束迭代器end()
//_perd 函数或谓词(返回bool类型的仿函数)
*/

//查找内置数据类型
class GreaterFive{
    public:
        bool operator()(int val){
            return val>5;
        }
};
void test01(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());
    if(it==v.end())
        cout<<"没找到"<<endl;
    else
        cout<<*it<<endl;

}

//查找自定义数据类型
class Person{
    public:
    string m_name;
    int m_age;
        Person(string name, int age){
            this->m_name=name;
            this->m_age=age;
        }
        
};
class Greater20{
    public:
        bool operator()(Person& p){
            return p.m_age>20;
        } 
};
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

    vector<Person>::iterator it=find_if(v.begin(),v.end(),Greater20());
    if(it==v.end())
        cout<<"NO"<<endl;
    else
        cout<<(*it).m_age<<endl;
}
int main(){
    //test01();
    test02();
}