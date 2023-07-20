#include <iostream>
#include <functional>
#include <vector>
#include <random>
using namespace std;

template<typename Compare, typename T>
class _mybind2nd{
public:
    _mybind2nd(Compare comp, T val): _comp(comp), _val(val){}
    
    bool operator()(const T& frist){
        return _comp(frist, _val);
    }
private:
    Compare _comp;
    T _val;
};

template<typename Compare, typename T>
_mybind2nd<Compare,T> mybind2nd(Compare comp, T value){
    return _mybind2nd(comp, value);
}

int myrand(int left = 0, int right = 100){
    std::random_device rd; // 用于获得真正的随机数种子
    std::default_random_engine gen(rd()); // 默认随机数引擎
    std::uniform_int_distribution<> dis(left, right); // 生成0到9之间的均匀分布

    // 生成随机整数
    return dis(gen);
}

void display(const vector<int>& v){
    for(auto & num : v) cout << num << " ";
    cout << endl;
}

void test_sysbind2nd(vector<int> vec){
    auto it = find_if(vec.begin(), vec.end(), bind2nd(less<int>(), 70));
    vec.insert(it, 70);
    display(vec);
}

void test_mybind2nd(vector<int> vec){
    auto it = find_if(vec.begin(), vec.end(), mybind2nd(less<int>(), 70));
    vec.insert(it, 70);
    display(vec);
}

int main(){
    vector<int> vec;
    vec.reserve(20);
    for(int i=0; i<20; ++i){
        vec.emplace_back(myrand());
    }
    display(vec);
    sort(vec.begin(), vec.end(), greater<int>());
    display(vec);
    cout << "===========================================================" << endl;
    test_sysbind2nd(vec);
    cout << "===========================================================" << endl;
    test_mybind2nd(vec);
}