#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int cooldown = 0;
    int buy = -prices[0];
    int sell = 0;
    int n = prices.size();

    for(int i=1; i<n; ++i){
        buy = max(buy, cooldown - prices[i]);
        cooldown = sell;
        sell = max(sell, buy + prices[i]);
    }
    return sell;
}

int main(){
    vector<int> prices = {1,2,3,0,2};
    cout << maxProfit(prices) << endl;
    return 0;
}