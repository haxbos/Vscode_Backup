#include<iostream>
using namespace std;
#define MAX_N 1005

//时间复杂度O(n²)
int N,V,wi[MAX_N],vi[MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    cin >> N >> V;
    for(int i=1; i<=N; i++)
        cin >> vi[i] >> wi[i];
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=V; ++j){
            if(j < vi[i])   
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - vi[i]] + wi[i]); 
        }
    }
    
    cout << dp[N][V] << endl;
}