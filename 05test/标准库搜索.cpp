#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//建议使用有序数组，不然可能查找不到数据
int main(){
    vector<int> arr = {1,2,2,5,7,9,2,4,5,6};
    sort(arr.begin(),arr.end());

    for(auto num : arr) cout << num << " ";
    cout << endl;

    //返回一个迭代器，指向第一个不小于 n 的元素 
    auto pos = lower_bound(arr.begin(),arr.end(),9);
    int idx = distance(arr.begin(),pos);    //求两个迭代器之间的距离
    cout << "*pos = " << *pos << endl;

}