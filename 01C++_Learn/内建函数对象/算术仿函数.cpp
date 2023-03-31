#include<iostream>
//使用内建函数对象需要引入头文件
#include<functional>
using namespace std;

/*原型
//其中，除了nagate 是一元运算，其他都是二元运算
1、template<class T> T plus<T>  //加法仿函数
2、template<class T> T minus<T> //减法仿函数
3、template<class T> T multiplies<T> //乘法仿函数
4、template<class T> T divides<T> //除法仿函数
5、template<class T> T modulus<T> //取模仿函数
6、template<class T> T negate<T> //取反仿函数
*/

//加、减、乘、除、取模的用法都是一样的
//加法仿函数
void test01(){
    plus<int>   p;
    cout<<p(10,22)<<endl;
}

//取反仿函数
void test02(){
    negate<int> n;
    cout<<n(20)<<endl;

}
int main(){
    test01();
    test02();
}