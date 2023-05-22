/*
深搜超时
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
const int MAX_N = 510;

int n,m,p,q;
int arr[MAX_N][MAX_N];
ll res;

void dfs(int i, int j, int sum0, int sum1){
    if(i == n-1 && j == m-1){
        if(sum0 >= p && sum1 >= q)  ++res;
        return;
    }

    if(arr[i][j] == 0)  ++sum0;
    else ++sum1;

    if(i+1 < n)    dfs(i+1,j,sum0,sum1);
    if(j+1 < m)    dfs(i,j+1,sum0,sum1);
}

int main(){
    cin >> n >> m >> p >> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
        }
    }
    int sum0=0 , sum1=0;
    dfs(0,0,sum0,sum1);
    cout << res % mod << endl;
}
/*
3 3 2 1
0 0 1
0 0 0
1 0 0
*/