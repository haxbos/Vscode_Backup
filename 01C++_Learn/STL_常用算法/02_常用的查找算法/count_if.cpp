#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*  按条件统计元素个数
count_if(iterator beg,iterator end,_pred);
//_pred 谓词
*/

//内置数据类型
// class GreaterFive{
//     public:
//         bool operator()(int val){
//             return val>5;
//         }
// };
bool GreaterFive(int val){
    return val>5;
}
void test01(){
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);

    int num=count_if(v.begin(),v.end(),GreaterFive);
    cout<<num<<endl;
}

//统计自定义数据类型
class Person{
    public:
        string m_name;
        int m_age;
        Person(string name,int age){
            this->m_name=name;
            this->m_age=age;
        }
};  
class GreaterAge{
    public:
        bool operator()(const Person& p){
            return p.m_age>20;
        }
};
void test02(){
    vector<Person> v;
    Person p1("刘备",29);
    Person p2("hah",20);
    Person p3("助手",29);
    Person p4("张三",15);
    Person p5("诸葛",4);
    Person p6("管给",2);
    Person p7("二分fe",29);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);

    int num=count_if(v.begin(),v.end(),GreaterAge());
    cout<<num<<endl;
}
int main(){
    //test01();
    test02();
}