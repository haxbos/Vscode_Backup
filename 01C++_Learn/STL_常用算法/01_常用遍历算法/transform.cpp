#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

/*  搬运容器到另一个容器中
transform(iterator beg1,iterator end,iterator beg2,_func);
//beg1 end   源容器开始和结束迭代器
//beg2      目标容器开始迭代器
//_func     函数或函数对象
*/

//打印
class PrintVector{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};
class Target{
    public:
        //函数可以对被搬运的数据进行操作
        int operator()(int val){

            return val+100;
            
            //return val;   直接返回原数
        }
};
void test01(){
    vector<int> v1;
    for(int i=0;i<10;i++)
        v1.push_back(i);

    cout<<"v1:"<<endl;
    for_each(v1.begin(),v1.end(),PrintVector());
    cout<<endl;

    vector<int> v2;
    //需要提前给目标容器开辟足够的空间，才能搬运成功，否则搬运不了
    v2.resize(v1.size());
    // for(int i=10;i>0;i++)
    //     v2.push_back(i);
    // cout<<"v2:"<<endl;
    // for_each(v2.begin(),v2.end(),PrintVector());

    cout<<"交换后："<<endl;
    transform(v1.begin(),v1.end(),v2.begin(),Target());
    cout<<"v2:"<<endl;
    for_each(v2.begin(),v2.end(),PrintVector());
}


int main(){
    test01();
}