#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
1、返回bool类型的仿函数称为谓词
2、如果operator()接受1个参数，称为一元谓词
3、如果operator()接受2个参数，称为二元谓词
*/

//一元谓词
class GetFive{
    public:
        bool operator()(int val){
            return val>5;
        }
};
void test01(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    //查找容器中有没有>5的数字
    //Getfive() 是匿名的函数对象
    vector<int>::iterator it=find_if(v.begin(),v.end(),GetFive());

    if(it==v.end())
        cout<<"没找到"<<endl;
    else
        cout<<"找到了："<<*it<<endl;
}

//二元谓词
class MyCompare{
    public:
        bool operator()(int val1,int val2){
            return val1>val2;
        }
};
void test02(){
    vector<int>  v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(50);
    v.push_back(70);
    v.push_back(30);

    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //使用函数对象，改变算法策略，变规则为从大到小
    sort(v.begin(),v.end(),MyCompare());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    //test01();
    test02();
}