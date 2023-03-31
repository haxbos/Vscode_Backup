#include <iostream>
#include <algorithm>
using namespace std;


void test01(){
    vector<int> vec;

    /*back inserter接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。
      当我们通过此迭代器赋值时，赋值运算符会调用push_back将一个具有给定值的元素添
      加到容器中：
     */
    auto it = back_inserter(vec);

    fill_n(it,10,1);

    for(auto num : vec) cout << num << " ";
}

void test02(){
    vector<int> vec(10);

    //写入数据的位置要足够大， 能容纳写入的元素
    //新定义的vector 没有初始化，size  为 0, 所以不能向里面写入
    fill_n(vec.begin(),10,1);

    for(auto num : vec) cout << num << " ";
}


void test03(){
    vector<int> v;
    v.resize(10);
    fill_n(v.begin(), 10, 1);
    cout << v.size() << endl;
    for(auto num : v) cout << num << " ";
}
int main(){
    //test01();
    //test02();
    test03();

}