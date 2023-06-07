#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int miniumSubarr(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int res = n+1;

        while(right < n){
            sum += nums[right];
            while(sum >= k){
                res = min(res, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return res == n+1 ? 0 : res;
    }
};

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int k = 7;
    Solution sol;
    int res = sol.miniumSubarr(nums,k);
    cout << res << endl;
    return 0;
}
