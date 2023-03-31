#include <iostream>
using namespace std;


/*甚至就算在类的内部定义该函数，我们也必须在类的外部提供相应的声明从而使得
 *函数可见。换句话说，即使我们仅仅是用声明友元的类的成员调用该友元函数，
 *它也必须是被声明过的
 */
class Person{
public:
    friend void myTeacherAdd(int a,int b);
    void myPerson(int a,int b);
    // void myPerson(int a,int b){
    //     myTeacherAdd(a,b);
    // }
};

void myTeacherAdd(int a,int b);

void Person::myPerson(int a,int b){
    myTeacherAdd(a,b);
}

void myTeacherAdd(int a,int b){
    cout << "i am Teacher " << a+b << endl;
}

int main(){
    Person p;
    p.myPerson(10,20);
}

