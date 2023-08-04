#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        int n = nums.size();
        vector<int> arr(2001,0);
        int total = 0;
        
        for(auto& num : nums){
            if(arr[num] == 0){
                ++arr[num];
                ++total;
            }
        }
        cout << "total : " << total << endl;
        if(total == 1) return n;
        
        
        for(int i=0; i<=n-total; ++i){
            vector<int> ans(2001,0);
            cnt = 0;
            for(int j=i; j<n; ++j){
                if(ans[nums[j]] == 0){
                   if(cnt == total - 1){
                       res += n - j;
                       
                       cout <<"i = " << i << " j = " << j <<  "  " << (n-j) << endl;
                       break;
                   }
                    ++ans[nums[j]];
                    ++cnt;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,1,2,2};
    cout << sol.countCompleteSubarrays(nums) << endl;
    return 0;
}