#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> vec;

void dfs(string s, int n, int num, vector<char> path){
    if(path.size() == n){
        vec.emplace_back(path);
        return;
    }

    for(int i=num; i<s.length(); ++i){
        dfs(s, n, i+1, path);
        path.emplace_back(s[i]);
        dfs(s, n, i+1, path);
    }
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<char> path;
    dfs(s, n, 0, path);
    for(auto &arr : vec){
        for(auto &num : arr)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}


