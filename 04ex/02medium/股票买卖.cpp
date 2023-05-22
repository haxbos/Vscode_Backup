#include <bits/stdc++.h>
using namespace std;

//贪心
int maxProfit1(vector<int>& prices) {
    int res = 0;
    int n = prices.size();

    for(int i=1; i<n; ++i){
        if(prices[i] > prices[i-1])
            res += prices[i] - prices[i-1];
    }
    return res;
}

//dp
int maxprofit2(vector<int> &prices){
    int n = prices.size();
    if(n < 2)   return 0;
    vector<vector<int>> dp(n,vector<int>(n,0));

    //0代表持有cash, 1代表stock
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for(int i=1; i<n; ++i){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][0]- prices[i],dp[i-1][1]);
    }
    return dp[n-1][0];
}

int main(){
    vector<int> p = {1};
    int res = maxprofit2(p);
    cout << res << endl;
}