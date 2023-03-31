#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*两个容器合并，并储存到另一容器中*/
//如果两个序列，都是有序的，并且都是降序或升序，那么合并后的结果也是

/*
merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
dest    是目标容器的开始迭代器 
*/

void PrintV(int val){
    cout<<val<<" ";
}
int main(){
    vector<int> v1={1,3,5,9,6,7};
    vector<int> v2={0,8,4,6,2,7};
    vector<int> v3;
    //目标容器需提前开辟空间
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),v3.end(),PrintV);
}