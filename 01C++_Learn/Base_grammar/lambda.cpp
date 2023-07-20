#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Data{
public:
    Data(const int& a, const int& b): m_a(a), m_b(b){}
    ~Data(){}
    int m_a;
    int m_b;
};

int main(){
    using FUNC = function<bool(Data, Data)>;
    priority_queue<Data, vector<Data>, FUNC> q([](const Data& d1, const Data& d2)->bool{
        return d1.m_a < d2.m_a;
    });

    q.push(Data(10,20));
    q.push(Data(30,20));
    q.push(Data(90,20));
    q.push(Data(14,20));
    q.push(Data(40,20));

    while (!q.empty()){
        cout << q.top().m_a << " " << q.top().m_b << endl;
        q.pop();
    }
    return 0;
}