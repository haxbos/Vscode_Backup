#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solution(vector<int>&arr1, vector<int>&arr2){
    unordered_map<int, int> hash;
    for(int i=0; i<arr2.size(); ++i){
        hash[arr2[i]] = i;
    }

    sort(arr1.begin(), arr1.end(), [&](int a, int b){
        if(hash.count(a) && hash.count(b)){
            return hash[a] < hash[b];
        }else if(hash.count(a)){
            return true;
        }else if(hash.count(b)){
            return false;
        }else{
            return a < b;
        }
    });
}

int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    solution(arr1, arr2);
    for(auto i: arr1){
        cout << i << " ";
    }
}