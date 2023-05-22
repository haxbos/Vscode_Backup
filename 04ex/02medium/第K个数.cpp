/*
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。
注意，不是必须有这些素因子，而是必须不包含其他的素因子。
例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
*/

#include <bits/stdc++.h>
using namespace std;

int getKthMagicNumber(int k) {
    vector<int> nums = {3,5,7};

    priority_queue<long,vector<long>,greater<long>> hash;
    unordered_set<long> seen;

    int res = 0;
    hash.push(1L);
    seen.insert(1L);

    for(int i=0; i<k; ++i){
        long cur = hash.top();
        hash.pop();

        res = (int)cur;

        for(auto &num : nums){
            long t = num * cur;
            if(!seen.count(t)){
                hash.push(t);
                seen.insert(t);
            }
        }
    }
    return res;
}

int main(){
    int k;
    cin >> k;
    int res = getKthMagicNumber(k);
    cout << res << endl;
}