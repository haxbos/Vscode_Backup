#include <bits/stdc++.h>
using namespace std;

//dp
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n =height.size();
//         int left = 0, right = 0, min_num = 0;
//         int ans = 0;
//         vector<int> left_max(n), right_max(n);
//         for(int i=1; i<n; ++i){
//             left_max[i] = max(left_max[i-1], height[i-1]);
//         }
//         for(int i=n-2; i>=0; --i){
//             right_max[i] = max(right_max[i+1], height[i+1]);
//         }

//         for(int i=1; i<n-1; ++i){
//             min_num = min(left_max[i], right_max[i]);
//             if(min_num > height[i])
//                 ans += min_num - height[i];
//         }
//         return ans;
//     }
// };

//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;
        int ans = 0;
        
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax <= rightMax){
            //if(height[left] < height[right]){
                ans += leftMax - height[left];
                ++left;
            }
            else{
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> height = {4,2,0,3,2,5};
    cout << sol.trap(height) << endl;
    return 0;
}