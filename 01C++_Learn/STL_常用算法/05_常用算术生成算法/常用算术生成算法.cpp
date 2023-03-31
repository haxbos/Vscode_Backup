#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<numeric>

/*算术生成算法属于小型算法  ，使用死包含头文件为#include<numeric> */
/*
1、accumulate(iterator beg,iterator end, value);      //value 为起始值，计算容器累计总和
2、fill(iterator beg,iterator end, value);     //value 填充的值，向容器中填充元素
*/

//accumulate
void test_accumulate(){
    vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    int total=accumulate(v1.begin(),v1.end(),10);
    cout<<total<<endl;
}

//fill
void MyPrint(int val){
    cout<<val<<" ";
}
void test_fill(){
    vector<int> v1;
    v1.resize(10,0);
    fill(v1.begin(),v1.end(),100);
    for_each(v1.begin(),v1.end(),MyPrint);
}
int main(){
    //test_accumulate();
    test_fill();
}