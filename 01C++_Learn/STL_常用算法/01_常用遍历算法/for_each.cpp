#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>


/*
for_each(iterator beg,iterator end,_func);
//遍历算法，遍历容器中的元素
//beg  end 都是迭代器，_func 函数 或者函数对象
*/

//普通函数
void PrintVector1(int val){
    cout<<val<<" ";
}

//仿函数
class PrintVector2{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};
void test01(){
    vector<int> v;
    for(int i=1;i<=10;i++){
        v.push_back(i);
    }

    for_each(v.begin(),v.end(),PrintVector1);
    cout<<endl;

    for_each(v.begin(),v.end(),PrintVector2());
    cout<<endl;
}

int main(){
    test01();
}