#include<iostream>
#include<functional>
using namespace std;
#include<vector>
#include<algorithm>

/*
1、template<class T> bool equal_to<T>   //等于
2、template<class T> bool not_equal_to<T>   //不等于
3、template<class T> bool greater<T>   //大于
4、template<class T> bool greater_equal<T>   //大于等于
5、template<class T> bool less<T>   //小于
6、template<class T> bool less_equal<T>   //小于等于
*/

class MyCompare{
    public:
        bool operator()(int v1,int v2){
            return v1>v2;
        }
};
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(70);
    v.push_back(50);
    v.push_back(20);

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    cout<<"==========="<<endl;
    //降序
    //sort(v.begin(),v.end(),MyCompare());

    //使用内置函数
    sort(v.begin(),v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
}