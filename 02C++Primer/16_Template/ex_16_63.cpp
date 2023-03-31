#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

template<typename T>
size_t count(vector<T> const& vec, T value){
    //0u表示无符号整数0
    auto cnt = 0u;

    for(auto const& elem : vec){
        if(value == elem) ++cnt;
    }
    return cnt;
}

//函数模板特化
template<>
size_t count(vector<const char*> const& vec, const char* value){
    auto cnt = 0u;
    for(auto const& elem : vec){
        if(strcmp(value, elem) == 0) ++cnt;
    }
    return cnt;
}

int main(){
    vector<double> vd = {1.1, 2.2, 3.3, 4.4, 5.5, 3.3, 7.7, 3.3, 9.9};
    cout << count(vd, 3.3) <<endl;

    vector<const char*> vcc = {"hi", "hello", "hi", "world", "hi"};
    cout << count(vcc, "hi") <<endl;
}