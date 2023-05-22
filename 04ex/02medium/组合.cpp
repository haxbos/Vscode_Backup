#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    vector<vector<int>> res;

    function<void(int,int,int)> dfs = [&](int n, int k, int num){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        for(int i=num; i<=n; ++i){
            path.push_back(i);
            dfs(n,k,i+1);
            path.pop_back();
        }
    };
    dfs(n,k,1);
    return res;
}

int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> res = combine(n,k);

    for(auto &arr : res){
        for(auto &num : arr){
            cout << num << " ";
        }
        cout << endl;
    }
}