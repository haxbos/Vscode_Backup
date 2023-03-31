#include <iostream>
using namespace std;
#include <string>

//p264
class Test{
public:
    Test():Test("name_test",66){
        cout <<this->m_name <<"default constructor" <<endl;
    }

    Test(string s):m_name(s){
        cout <<this->m_name <<" string , constructor" << endl;
    }
    Test(string s ,int val):m_name(s),m_val(val){
        
        cout <<this->m_name << "string ,val constructor" << endl;
    }

    void myPrint(const Test& t){
        cout << t.m_name << endl;
    }
private:
    string m_name;
    int m_val;
};

int main(){
    Test t("haha");
    string str = "xixi";
    t.myPrint(str);
}
