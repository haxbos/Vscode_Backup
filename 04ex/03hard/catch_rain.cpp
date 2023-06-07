#include <iostream>
#include <vector>
using namespace std;

//dp
class Solution{
public:
    int trapdp(vector<int>& height){
        int n = height.size();
        vector<int> left_max(n,0);
        vector<int> right_max(n,0);
        int ans = 0;
        for(int i=1; i<n; ++i){
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        for(int i=n-2; i>=1; --i){
            right_max[i] = max(right_max[i+1], height[i+1]);
        }

        for(int i=1; i<n-1; ++i){
            int min_num = min(left_max[i], right_max[i]);
            if(min_num > height[i])
                ans += min_num - height[i];
        }
        return ans;
    }

    int trapDoublePoint(vector<int>& height){
        int n = height.size();
        int leftMax = 0, rightMax = 0, ans = 0, left = 0, right = n-1;

        while(left < right){
            leftMax = max(leftMax, height[left]);   //左边最大值
            rightMax = max(rightMax, height[right]); //右边最大值
            if(leftMax <= rightMax){
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
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trapdp(height) << endl;
    cout << sol.trapDoublePoint(height) << endl;
    return 0;
}