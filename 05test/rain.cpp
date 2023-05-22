#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int left = 0, right = 0, min_num = 0;
        int ans = 0;

        for(int i=1; i<n-1; ++i){
            left = *max_element(height.begin(), height.begin()+i);
            right = *max_element(height.begin()+i+1, height.end());
            min_num = min(left, right);
            if(min_num > height[i])
                ans += min_num - height[i];
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