#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<string> &arr, int l, int r){
    if(l >= r)  return;
    int i = l, k = r;
    string temp = arr[l];

    while(i < k){
        while(i < k && arr[k] >= temp)   --k;
        while(i < k && arr[i] <= temp)   ++i;
        swap(arr[i],arr[k]);
    }
    swap(arr[l],arr[i]);
    for(auto num : arr) cout << num << " ";
    cout << endl;
    quickSort(arr,l,i-1);
    quickSort(arr,i+1,r);
}

void test(){
    vector<string> arr = {"tang","deng","an","wan","shi","bai","fang","li"};
    cout << "originate : ";
    for(auto num : arr) cout << num << " ";
    cout << endl;
    quickSort(arr,0,arr.size()-1);

}
int main(){
    // vector<int> arr = {1,5,8,9,6,3,2,4,7,0};
    // quickSort(arr,0,arr.size()-1);
    // for(auto &num : arr)
    //     cout << num << " ";

    test();
}