#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;

int sumSubarrayMins(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    ll res = 0;
    vector<int> path;
    function<void (int) > dfs = [&](int num){
        if(path.size()) {
            for(auto num : path){
                cout << num << " ";
            }
            cout << endl;
        }
        if(num >= n){
            return;
        }

        for(int i=num; i<n; ++i){
            path.push_back(arr[i]);
            dfs(i+1);
            path.pop_back();
        }
    };
    dfs(0);
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int res = sumSubarrayMins(arr);
    cout << res << endl;
}