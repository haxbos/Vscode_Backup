#include <iostream>
#include <string>
using namespace std;

void hello(string s){ cout << s << endl; }
int sum(int a, int b) { return a+b; }

template<typename ty>
class myfunction{};

template<typename R, typename... A>
class myfunction<R(A...)>{
public:
    using PFUNC = R(*)(A...);
    myfunction(PFUNC pfunc): _pfunc(pfunc){}
    R operator()(A... arg){
        return _pfunc(arg...);
    }
private:
    PFUNC _pfunc;
};

int main(){
    myfunction<void(string)> myfunc1 = hello;
    myfunc1("hello,world");
    myfunction<int(int,int)> myfunc2(sum);
    cout << myfunc2(10,20) << endl;
}