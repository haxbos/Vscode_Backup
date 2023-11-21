#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<string>

/* 查找重复相邻的元素*/

/*
adjacent_find(iterator beg,iterator end);
//查找相邻元素，返回相邻第一个元素的迭代器 ,没找打返回结束迭代器end()
*/

void test01(){
    vector<int> v = {1,2,3,3,3,2,4,4};
    
    vector<int>::iterator it=adjacent_find(v.begin(),v.end());
    if(it==v.end())
        cout<<"NO"<<endl;
    else
        cout<<*it<<endl;
}
int main(){
    test01();
}