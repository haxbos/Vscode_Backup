#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int moveVal(vector<int>& nums, int val){
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right){
            if(nums[left] == val){
                swap(nums[left],nums[right]);
                --right;
                continue;
            }
            ++left;
        }
        return left;
    }
};

int main(){
    vector<int> nums = {2,2,2,2};
    int val = 2;
    Solution sol;
    int res = sol.moveVal(nums,val);
    cout << res << endl;
    for(int i=0; i<res; ++i)
        cout << nums[i] << " ";
    return 0;
}