#include <bits/stdc++.h>
using namespace std;

class states_cale{
private:
    int m_a;
    int m_b;
public:
    states_cale(int a,int b){
        m_a = a;
        m_b = b;
    }
    states_cale& combine(const states_cale &rhs);
    void myPrint();
};

// 相当于 使用了 +=  ，调用者是左值，参数为右值，最后的到的结果也是左值
//更新调用者当前的值
states_cale& states_cale::combine(const states_cale &rhs){
    m_a += rhs.m_a;
    m_b += rhs.m_b;
    return *this;
}

void states_cale::myPrint(){
    printf("m_a = %d , m_b = %d\n",m_a,m_b);
}

int main(){
    states_cale test1(4,6);
    states_cale rhs(10,3);
    test1.combine(rhs);
    test1.myPrint();
}