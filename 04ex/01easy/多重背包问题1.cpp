#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 110;

int N,V;
int v[MAX_N],w[MAX_N],s[MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    cin >> N >> V;
    for(int i=1; i<=N; ++i)
        cin >> v[i] >> w[i] >> s[i];

    for(int i=1; i<=N; ++i){
        for(int j=0; j<=V; ++j){
            for(int k=0; k<=s[i] && k*v[i] <= j; ++k){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]] + k*w[i]);
            }
        }
    }
    cout << dp[N][V] << endl;
}

/*
4 5
1 2 3
2 4 1
3 4 3
4 5 2
*/