#include <bits/stdc++.h>
using namespace std;

//把一个数字插入到一个有序数组中
//时间复杂度：O(n^2)
//空间复杂度：O(1)
//稳定排序

void insertSort(vector<int> &arr){
    int n = arr.size();

    for(int i=1; i<n; ++i){
        int pre = i-1;
        int cur = arr[i];
        for(; pre >= 0 &&arr[pre] > cur; --pre){
            arr[pre+1] = arr[pre];
        }
        arr[pre+1] = cur;
    }
}

int main(){
    vector<int> arr = {0,1,4,7,8,5,2,3,6,9};
    insertSort(arr);

    for(auto &num : arr){
        cout << num << " ";
    }
}