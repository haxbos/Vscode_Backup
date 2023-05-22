#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        sort(barcodes.begin(), barcodes.end());
        int num = barcodes[0], cnt = 0, maxCnt = 0, maxNum = 0;
        for(int i=0; i<n; ++i){
            if(barcodes[i] == num){
                ++cnt;
            }
            else{
                if(cnt > maxCnt){
                    maxCnt = cnt;
                    maxNum = num;
                }
                num = barcodes[i];
                cnt = 1;
            }
        }
        cout << maxNum << " " << maxCnt << endl;
        vector<int> ans(n);
        int i = 0;
        for(;i<n && maxCnt > 0; i+=2){
            ans[i] = maxNum;
            --maxCnt;
        }
        int idx = 0;
        while(idx < n){
            for(; i<n; i+=2){
                while(barcodes[idx] == maxNum){
                    ++idx;
                }
                ans[i] = barcodes[idx++];
            }
            for(i=1; i<n; i+=2){
                while(barcodes[idx] == maxNum){
                    ++idx;
                }
                ans[i] = barcodes[idx++];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,2,1,3};
    vector<int> ans = sol.rearrangeBarcodes(vec);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}