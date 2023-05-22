#include <bits/stdc++.h>
using namespace std;

int numberOf1Between1AndN_Solution(int n) {
    int dp[10] = {0};
    int len = 0;
    int num = n;
    int s = 0;
    while(num){
        s = num %10;
        num /= 10;
        ++len;
    }
    
    for(int i=1; i<len; ++i){
        dp[i] = dp[i-1] * 10 + pow(10,i-1);
    }
    
}

int main(){
    int n;
    cin >> n;

    int res = numberOf1Between1AndN_Solution(n);
    cout << res << endl;
}