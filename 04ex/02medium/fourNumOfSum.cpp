#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(auto& j: nums){
            cout << j << " ";
        }
        cout << endl;

        int n = nums.size();
        int left = 0, right = n-1;

        for(int i=0; i<n-3; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n-2; ++j){
                if(nums[i] + nums[j] > target && nums[j] >=0) break;
                if(j>i+1 && nums[j]==nums[j-1] ) continue;
                left = j+1, right = n-1;
                int sum = target - nums[i] - nums[j];
                
                while(left < right){
                    if(nums[left] + nums[right] > sum)  --right;
                    else if(nums[left] + nums[right] < sum) ++left;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while(left < right && nums[left]==nums[left-1]) ++left;
                        while(left < right && nums[right]==nums[right+1]) --right;
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    vector<vector<int>> res = sol.fourSum(nums, target);
    for(auto& i: res){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}