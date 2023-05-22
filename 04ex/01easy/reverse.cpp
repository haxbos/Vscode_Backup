#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> res;
    int num = 0;
    int n = 0;
    cin >> n;

    for(int i=0; i<n; ++i){
        cin >> num;
        res.push_back(num);
    }
    reverse(res.begin(),res.end());
    for(auto a : res){
        cout << a << endl;
    }
}