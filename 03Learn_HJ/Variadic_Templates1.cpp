#include <iostream>
#include <bitset>
using namespace std;

void print(){}

//特化
//... 就是一个所谓的包
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args){
    //在最后包中剩下一个参数的时候，当那个参数被出输出后
    //包中就没有参数了，但是此时，还是会调用一次 print 函数
    //所以 需要构造一个 无参的 print 函数，来避免错误
    //其他使用 ... 的函数也是类似（main 函数除外）
    cout << "1 + n value" << endl;
    cout << firstArg << endl;
    print(args...);
}

//泛化
template<typename... Types>
void print(const Types&... args){
    cout << "m value" << endl;
    //cout << args[0] << endl;
    print(args...);
}

int main(){
    //当存在多个同名版本的模板都与参数匹配，都可以调用时，会优先调用特化版本的模板
    print(7.5,"hello",bitset<16>(377),42);
    return 0;
}