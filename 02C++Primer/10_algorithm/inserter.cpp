#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*在使用这些 迭代器时，都必须在支持该迭代器的容器下使用*/

//inserter 是在指定的迭代器之前插入, 不会改变插入的顺序
void test01(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> arr2 = {0,0,0,0,0};
    copy(arr.begin(),arr.end(),inserter(arr2,arr2.begin() + 2));
    for(auto num : arr2)    cout << num << " ";
}

//front_inserter 是在容器最前面插入，因此插入的元素的顺序的会倒置
void test02(){
    list<int> lst = {1,2,3,4,5};
    list<int> lst2;
    copy(lst.begin(),lst.end(),front_inserter(lst2));
    for(auto num : lst2)    cout << num << " ";
}

void test03(){
    list<int> lst = {1,2,3,4,5};
    list<int> lst2 = {0,0,0,0,0};
    
    //auto it = lst2.begin();

    auto it = inserter(lst2, lst2.begin());

    list<int> lst3;
    copy(lst.begin(),lst.end(), it);

    for(auto num : lst2) cout << num << " ";

}
int main(){
    //test01();
    //test02();
    test03();
}