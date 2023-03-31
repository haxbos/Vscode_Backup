#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main(){
    list<int> lst(5,4);
    vector<int> vec(5,8);

    vector<double> vec2(lst.begin(),lst.end());
    for(auto num : vec2)
        cout << num << " ";
    cout << endl;
    /*当创建一个容器为宁一个容易的拷贝时，需要保证两个容器的类型一致，才能拷贝*/
    //vector<double> vec3 = vec;
    //vector<double> vec3(vec);

    /*当使用迭代器进行拷贝时，只要保证两个容器内的类型能进行隐式转换就行*/
    vector<double> vec3(vec.begin(),vec.end());
    for(auto num : vec3)
        cout << num << " ";
}