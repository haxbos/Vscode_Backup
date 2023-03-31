#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

/*二分查找法*/
/*查找指定元素是否存在
binary_search(iterator beg,iterator end,value);
//找到返回true，没找到，返回false
//注：在无序序列中不可用
*/

int main(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    //这个容器必须是个有序的序列
    bool flag=binary_search(v.begin(),v.end(),5);
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}