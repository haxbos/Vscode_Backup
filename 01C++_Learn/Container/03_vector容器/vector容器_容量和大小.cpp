#include<iostream>
#include<vector>
using namespace std;

/*函数原型
empty() //判断容器是否为空
capacity()  //判断容器的容量
size()  //判断容器的大小

resize(int num);    //重新指定容器的大小  如果容器变大，多出的那部分默认填充0
                                        如果变小，则删除多余的部分
resize(int num,elem);   //如果容器变大，多出的那部分填充 elem
                          如果变小，则删除多余的部分    

*/
void PrintVector(vector<int>& vec)
{
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
/*vector容器 容量和大小操作*/
int main()
{
    vector<int> v;
    if(v.empty())   //为真代表容器为空
    {
        cout<<"v is null!"<<endl;
    }
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    if(!v.empty())
    {
        cout<<"v is't null"<<endl;
        cout<<"v capacity : "<<v.capacity()<<endl;
        cout<<"v size : "<<v.size()<<endl;
    }
    PrintVector(v);

    //重新指定大小   超出
    // v.resize(15);    //多余部分默认用 0 填充
    // PrintVector(v);

    //重载版本
    v.resize(15,100);   //利用重载版本，可以指定更改默认的数值，如果小于原来的小大，则没有影响
    PrintVector(v);
    cout << "v size is 15, capacity : " << v.capacity() << endl;

    //小于原来的大小，超出部分会删除
    v.resize(5);
    PrintVector(v);
    cout << "v size is 5, capacity : " << v.capacity() << endl;

}