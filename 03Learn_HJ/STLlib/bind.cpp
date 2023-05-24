#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

double my_divide(double x, double y){
    return x/y;
}

class myPair
{
public:
    double a, b;
    double multiply(){return a*b;}
};

void test_bind_function(){

    auto fn_five = bind(my_divide, 10, 2);      // 10/2
    cout << fn_five() << endl;

    //使用占位符
    auto fn_half = bind(my_divide, _1, 2);      // x/2
    cout << fn_half(10) << endl;

    //参数的顺序可以改变
    auto fn_invert = bind(my_divide, _2, _1);   // y/x
    cout << fn_invert(10, 2) << endl;

    auto fn_rounding = bind<int>(my_divide, _1, _2);   // (int)x/y
    cout << fn_rounding(10, 3) << endl;
}

void test_bind_memberFunc(){
    myPair ten_two{10,2};

    //member function 有一个额外的参数 this，即对象本身
    //所以占位符_1代表对象本身，_2代表第一个参数
    auto fn_member = bind(&myPair::multiply, _1);   // _1.multiply()
    cout << fn_member(ten_two) << endl;

    auto fn_member2 = bind(&myPair::a, ten_two);    // ten_two.a
    cout << fn_member2() << endl;

    auto fn_member3 = bind(&myPair::b, _1);       // _1.b
    cout << fn_member3(ten_two) << endl;
}

void test_fanFunc(){
    vector<int> arr{40,32,78,2,35,39,75,48,50};

    int n = count_if(arr.begin(), arr.end(), not1(bind2nd(less<int>(), 40)));
    cout << n << endl;

    auto fn_ = bind2nd(less<int>(), 40);
    cout << count_if(arr.begin(), arr.end(), fn_) << endl;
    cout << count_if(arr.begin(), arr.end(), bind(less<int>(), _1, 40)) << endl;
}

int main(){
    test_bind_function();

    cout << "=====================" << endl;

    test_bind_memberFunc();

    cout << "=====================" << endl;

    test_fanFunc();
    return 0;
}