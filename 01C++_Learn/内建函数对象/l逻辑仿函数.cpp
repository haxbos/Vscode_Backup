#include<iostream>
#include<functional>
#include<vector>
using namespace std;
#include<algorithm>

//逻辑仿函数实际应用较少
/*
1、template <calss T>  bool logical_and<T> //逻辑与
2、template <calss T>  bool logical_or<T> //逻辑或
3、template <calss T>  bool logical_not<T> //逻辑非
*/

int main(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);

    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    cout<<"============"<<endl;
    //利用逻辑非，将容器v 搬运到容器v2中，并执行取反操作
    //目标容器需提前开辟空间
    vector<bool> v2;
    v2.resize(v.size());

    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
}