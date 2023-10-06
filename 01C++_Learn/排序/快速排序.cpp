#include <bits/stdc++.h>
using namespace std;

template<class T>
void quickSort(vector<T> &arr, int start, int end){
    if(start >= end)  return;
    int left = start, right = end;
    T mid = arr[start];

    while(left < right){
        while(left < right && arr[right] >= mid)   --right;
        while(left < right && arr[left] <= mid)   ++left;
        swap(arr[left],arr[right]);
    }
    swap(arr[start],arr[left]);
    // for(auto num : arr) cout << num << " ";
    // cout << endl;
    quickSort(arr,start,left-1);
    quickSort(arr,left+1,end);
}

template<class T>
void printVector(vector<T> &arr){
    for(auto& num : arr) cout << num << " ";
    cout << endl;
}

void testString(){
    vector<string> arr = {"tang","deng","an","wan","shi","bai","fang","li"};
    cout << "originate : ";
    printVector<string>(arr);
    quickSort<string>(arr,0,arr.size()-1);
    printVector<string>(arr);
}

void testInt(){
    vector<int> arr = {1,5,8,9,6,3,2,4,7,0};
    printVector<int>(arr);
    quickSort(arr,0,arr.size()-1);
    printVector<int>(arr);
}

int main(){
    //testString();
    testInt();
}