#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> hash;
    vector<int> arr = {1,2,3,4,5,6,5,4,1,7,8,9,5,2};
    for(auto num : arr){
        hash[num]++;
    }

    for(auto num : hash){
        cout << "first : " << num.first << "  second : " << num.second << endl;
    }
}