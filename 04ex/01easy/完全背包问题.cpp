#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1010;

int N,V;
int vi[MAX_N],wi[MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    cin >> N >> V;
    for(int i=1; i<=N; ++i){
        cin >> vi[i] >> wi[i];
    }

    for(int i=1; i<=N; ++i)
        for(int j=0; j<=V; ++j){
            dp[i][j] = dp[i-1][j];
            if(vi[i] <= j){
                //在同一层中，直接在前一个刚好装下的地方，加
                dp[i][j] = max(dp[i][j],dp[i][j-vi[i]] + wi[i]);
            }
        }
            
    // for(int i=1; i<=N; ++i)
    //     for(int j=0; j<=V; ++j)
    //         for(int k=0; k*vi[i]<=j; ++k){
    //             dp[i][j] = max(dp[i][j],dp[i-1][j-k*vi[i]] + k*wi[i]);
    //         }
    cout << dp[N][V] << endl;
}

/*
4 5
1 2
2 4
3 4
4 5
*/