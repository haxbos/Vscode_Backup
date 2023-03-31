#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1、copy(iterator beg,iterator end,iterator dest);   //将容器内指定范围的元素拷贝到另一容器中
2、replace(iterator beg,iterator end,oldValue,newValue);  //将容器中指定范围的旧元素修改为新元素
3、replace_if(iterator beg,iterator end, _pred, newValue);   //将容器指定范围内满足条件的元素替换为新元素
4、swap(container v1,container v2); //互换两个容器的元素
*/

//copy
void PrintVector(int val){
    cout<<val<<" ";
}
void test_copy(){
    vector<int> v1={1,2,3,4,5,6,7};
    vector<int> v2;
    //提前给目标容器开辟空间
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());
    for_each(v2.begin(),v2.end(),PrintVector);
}

//replace
class MyPrint{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};
void test_replace(){
    vector<int> v1={2,3,6,5,4,2,5,66,9,2};
    cout<<"替换前："<<endl;
    for_each(v1.begin(),v1.end(),MyPrint());
    cout<<endl;
    cout<<"替换后："<<endl;
    //会替换所有符合的值
    replace(v1.begin(),v1.end(),2,88);
    for_each(v1.begin(),v1.end(),MyPrint());
}

//replace_if
class Great_equal5{
    public:
        bool operator()(int val){
            return val>=5;
        }
};
void test_rpif(){
    vector<int> v1={2,3,6,5,4,2,5,66,9,2};
    cout<<"替换前："<<endl;
    for_each(v1.begin(),v1.end(),MyPrint());
    cout<<endl;
    cout<<"替换后："<<endl;
    replace_if(v1.begin(),v1.end(),Great_equal5(),88);
    for_each(v1.begin(),v1.end(),MyPrint());
    
}


//swap
//互换的数据类型必须相同
void test_swap(){
    vector<int> v1={9,2,3,5,4,6,1,8};
    vector<int> v2={1,2,3,4,5,6,7,8,9};
    swap(v1,v2);
    cout<<"v1:"<<endl;
    for_each(v1.begin(),v1.end(),PrintVector);
    cout<<endl;
    cout<<"v2:"<<endl;
    for_each(v2.begin(),v2.end(),PrintVector);
}
int main(){
    //test_copy();
    //test_replace();
    //test_rpif();
    test_swap();   
}