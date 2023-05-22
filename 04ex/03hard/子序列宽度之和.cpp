#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    auto sumSubseqWidths(vector<int>& nums) {
        typedef long long ll;
        ll res = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> arr;

        function<void (int)> dfs = [&] (int num){
            if(!path.empty()){
                arr.push_back(path);
                // res =(res + path.back() - path.front()) % mod; 
                // cout << path.back() - path.front() << endl;
            }

            for(int i=num; i<n; ++i){
                path.emplace_back(nums[i]);
                dfs(i+1);
                path.pop_back();
            }
        };

        dfs(0);
        return arr;
        //return res;
    }
};

int main(){
    vector<int> nums = {2,1,3};
    Solution st;
    vector<vector<int>> arr = st.sumSubseqWidths(nums);

    for(auto &lst : arr){
        for(auto &num : lst){
            cout << num << " ";
        }
        cout << endl;
    }
    
}