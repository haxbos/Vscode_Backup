#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    vector<int> arr={10,20,30,1,2,3,5};
    cout << arr.data() << endl; //获取容器首地址
    cout << arr.max_size() << endl;
    auto item = find(arr.begin(),arr.end(),2);
    if(item == arr.end())
        cout << " Not found" << endl;
    else 
        cout << " Found" << endl;
}