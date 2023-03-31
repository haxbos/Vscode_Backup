#include<iostream>
using namespace std;

//继承中是先构造父类，在构造子类，析构相反
class Base
{
    public:
        
        Base()
        {
            cout<<"This is Base's Ctor"<<endl;
        }
        ~Base()
        {
            cout<<"This is Base's Dtor"<<endl;
        }
};

class Son:public Base
{
    public:
        
        Son()
        {
            cout<<"This is Son's Ctor"<<endl;
        }
        ~Son()
        {
            cout<<"This is Son's Dtor"<<endl;
        }
};
int main()
{
    Son s;
}