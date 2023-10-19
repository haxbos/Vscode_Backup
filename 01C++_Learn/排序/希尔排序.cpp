#include <bits/stdc++.h>
using namespace std;

//采用插入排序，先让间隔为gap的元素有序，再减小gap，直至gap为1
//时间复杂度：O(nlogn)
//空间复杂度：O(1)
//不稳定排序

void shellSort(vector<int> &arr){
    int len = arr.size();
    int gap = len/2;    //希尔增量

    while(gap){
        for(int i=gap; i<len; ++i){
            int pre = i-gap;
            int cur = arr[i];   //保留当前数据，后续原位置需要与其他位置交换，方便后续交换

            for(; pre >=0 && arr[pre] > cur; pre -= gap){   //一个以增量为间隔的简单插入排序
                arr[pre + gap] = arr[pre];
            }
            arr[pre + gap] = cur;
        }
        gap /= 2;
    }
}

int main(){
    vector<int> arr = {1,4,7,8,5,2,3,6,9,0};
    shellSort(arr);

    for(auto &num : arr)
        cout << num << " ";
}