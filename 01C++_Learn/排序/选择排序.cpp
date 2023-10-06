#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; ++i){
        int minIndex = i;
        for(int j=i+1; j<n; ++j){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    vector<int> arr = {0,1,4,7,8,5,2,3,6,9};
    for(auto &num : arr)
        cout << num << " ";
    cout << endl;
    selectionSort(arr);

    for(auto &num : arr)
        cout << num << " ";
}