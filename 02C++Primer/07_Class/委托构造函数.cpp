#include <iostream>
using namespace std;
#include <string>

//先执行 委托 的构造函数，执行完毕后 ，在执行自己的构造函数
class Test{
public:
    Test():Test("name_test",66){
        cout <<"默认构造" <<endl;
    }

    Test(string s):Test(s,77){
        cout <<"string , 构造" << endl;
    }
    Test(string s ,int val):m_name(s),m_val(val){
        
        cout << "string ,val 构造" << endl;
    }
    void myPrint(){
        cout << this->m_name <<" " << this->m_val << endl;
    }
private:
    string m_name;
    int m_val;
};

int main(){
    Test t("哈哈");
    t.myPrint();
}
