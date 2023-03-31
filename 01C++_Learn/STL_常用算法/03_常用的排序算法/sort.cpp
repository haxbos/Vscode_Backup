#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*排序  默认从小到大
sort( iterator beg,iterator end,_pred);
//_pred 谓词
*/

//内置数据
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(90);
    v.push_back(2);
    v.push_back(20);
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    //改为降序
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

//自定义数据
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
        bool operator()(Person & p1,Person & p2){
            return p1.m_age>p2.m_age;
        }
};
void test02(){
    vector<Person> v;
    Person p1("刘备",29);
    Person p2("hah",20);
    Person p3("助手",23);
    Person p4("张三",15);
    Person p5("诸葛",4);
    Person p6("管给",2);
    Person p7("二分fe",59);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);

    sort(v.begin(),v.end(),GreaterAge());
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<it->m_name<<"\t"<<it->m_age<<endl;
    }
}
int main(){
    //test01();
    test02();
}