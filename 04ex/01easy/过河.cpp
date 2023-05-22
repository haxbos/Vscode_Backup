#include <bits/stdc++.h>
using namespace std;

int L,S,T,M;

int st[110];
int dp[110];

int main(){
    cin >> L >> S >> T >> M;
    int num = 0;
    for(int i=0; i<=M; ++i){
        cin >> num;
        st[num] = 1;
    }

    int left = 0;
    for(int i=1; i<=L; ++i){
        if(i - left < S)    dp[i] = dp[i-1];
        else{

        }
    }
}