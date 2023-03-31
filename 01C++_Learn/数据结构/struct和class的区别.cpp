#include<iostream>
using namespace std;
#include<string>


/*struct和class 的区别
*struct所有的属性默认是public
*class中所有成员属性默认为private
*/
struct Student{
    int m_age;
    string m_name;
    Student(){};
    Student(int age,string name){
        this->m_age=age;
        this->m_name=name;
    }
};
int main(){
    Student* stu=new Student(18,"张三");
    cout<<stu->m_name<<"\t"<<stu->m_age<<endl;
    return 0;
}