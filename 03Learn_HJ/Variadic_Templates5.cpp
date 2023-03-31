#include <iostream>
#include <tuple>
#include <string>
#include <bitset>
using namespace std;

template<int idx, int Max, typename... Args>
class PrintTuple{
public:
    static void print(ostream& os, const tuple<Args...>& t){
        os << get<idx>(t) << (idx + 1 == Max ? "": ",");
        PrintTuple<idx+1, Max, Args...>::print(os,t);
    }
};

template<int Max,typename... Args>
class PrintTuple<Max,Max, Args...>{
public:
    static void print(ostream& os, const tuple<Args...>& t){}
};

template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t){
    os << "[";
    PrintTuple<0, sizeof...(Args),Args...>::print(os,t);
    return os << "]";
}

int main(){
    // output --> [7.5,hello,0000000101111001,42]
    cout <<make_tuple(7.5,string("hello"),bitset<16>(377),42);
}