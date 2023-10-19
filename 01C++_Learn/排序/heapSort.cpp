#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int heapSort(vector<int> &arr, int k){
    priority_queue<int, vector<int>, less<int>> pq;
    for(auto &num : arr){
        if(pq.size() < k){
            pq.push(num);
        }
        else{
            if(num < pq.top()){
                pq.pop();
                pq.push(num);
            }
        }
    }

    return pq.top();
}

int main(){
    vector<int> arr = {1,4,7,8,5,2,3,6,9};
    int k = 3;
    cout << "The " << k << "th smallest number is: " << heapSort(arr, k) << endl;
}