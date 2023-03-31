#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1、set_intersection(beg1,end1,beg2,end2,dest);  //两个集合必须是有序序列，并且顺序一致，求两个集合的交集
2、set_union(beg1,end1,beg2,end2,dest);    //两个集合必须是有序序列，并且顺序一致，求两个集合的并集
3、set_difference(beg1,end1,beg2,end2,dest);     //两个集合必须是有序序列，并且顺序一致，求两个集合的差集
*/

//set_intersection
void MyPrint(int val){
    cout<<val<<" ";
}
void test_Set_intersection(){
    vector<int> v1={1,2,3,4,5,6,7,8,9};
    vector<int> v2={5,6,7,8,9,10,11,12};
    vector<int> dest;
    int n=v1.size()<v2.size()?v1.size():v2.size();
    dest.resize(n,0);
    vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),dest.begin());
    //使用迭代器接收最后一个相同元素的后一位，可以避免输出dest中的后面多余的0
    for_each(dest.begin(),itEnd,MyPrint);
    cout<<endl;
    //如果只是输出dest中的元素，会把后面多出来的空间中所包含的0也一起输出
    for_each(dest.begin(),dest.end(),MyPrint);
}

//set_union
void test_union(){
    vector<int> v1={1,2,3,4,5,6,7,8,9};
    vector<int> v2={5,6,7,8,9,10,11,12};
    vector<int> dest;
    dest.resize(v1.size()+v2.size(),0);
    vector<int>::iterator itEnd=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),dest.begin());
    for_each(dest.begin(),itEnd,MyPrint);
    cout<<endl;
    for_each(dest.begin(),dest.end(),MyPrint);
}

//set_difference
void test_difference(){
    vector<int> v1={1,2,3,4,5,6,7,8,9};
    vector<int> v2={5,6,7,8,9,10,11,12};
    vector<int> dest1,dest2;
    dest1.resize(v1.size(),0);  //v1-v2
    dest2.resize(v2.size(),0);  //v2-v1
    vector<int>::iterator itEnd1=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),dest1.begin());
    vector<int>::iterator itEnd2=set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),dest2.begin());
    for_each(dest1.begin(),itEnd1,MyPrint);
    cout<<endl;
    for_each(dest2.begin(),itEnd2,MyPrint);

}
int main(){
    //test_Set_intersection();
    //test_union();
    test_difference();
}