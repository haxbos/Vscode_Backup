#include <iostream>
#include <vector>
using namespace std;

static int count_Ctor = 0;
static int count_copy_Ctor = 0;
static int count_move_Ctor = 0;
static int count_Dtor = 0;

class Test{
public:
    Test(int a, int b) : m_a(a), m_b(b){
        cout << "Test(int a, int b) " << count_Ctor++ << " a = " << m_a << " b = " << m_b << endl;
    }
    ~Test(){
        cout << "~Test()" << count_Dtor++ << " a = " << m_a << " b = " << m_b << endl;
    }

    Test(Test&& rhs) noexcept {
        if (this == &rhs) return;

        this->m_a = std::move(rhs.m_a);
        this->m_b = std::move(rhs.m_b);
        cout << "Test(Test&& rhs) " << count_move_Ctor++ << " a = " << m_a << " b = " << m_b << endl;
    }
    
    Test(const Test& rhs){
        if(this == &rhs) return;

        this->m_a = rhs.m_a;
        this->m_b = rhs.m_b;
        cout << "Test(const Test& rhs) " << count_copy_Ctor++ << " a = " << m_a << " b = " << m_b << endl;
    }

private:
    int m_a;
    int m_b;
};


void test_push_back(){
    vector<Test> vec;
    vec.reserve(5);
    for(int i=0; i<5; ++i){
        Test T(i, i+1);
        vec.push_back(T);
        //cout <<vec.size() << " " << vec.capacity() << endl;
    }
}

void test_empalce_back(){
    vector<Test> vec;
    vec.reserve(5);
    for(int i=0; i<5; ++i){
        Test T(i, i+1);
        vec.emplace_back(T);
    }
}

void test_reference(){
    vector<Test> vec;
    Test t{10,20};
    vec.reserve(10);
    vec.push_back(t);
    cout << "====================" << endl;
    vec.push_back(Test{20,20});
    cout << "====================" << endl;
    vec.emplace_back(Test{30,30});
    cout << "====================" << endl;
    vec.emplace_back(t);
    
}

int main(){
    // test_push_back();
    // cout << "---------------------" << endl;
    // test_empalce_back();

    test_reference();
}