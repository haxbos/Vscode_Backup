#include <iostream>
#include <vector>
using namespace std;

vector<int> goodIndices(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> f(n), g(n);
    for (int i = 0; i < n; i ++ ) {
        f[i] = 1;
        if (i && nums[i] <= nums[i - 1])
            f[i] = f[i - 1] + 1;
    }
    for (int i = n - 1; i >= 0; i -- ) {
        g[i] = 1;
        if (i + 1 < n && nums[i] <= nums[i + 1])
            g[i] = g[i + 1] + 1;
    }
    vector<int> res;
    for (int i = k; i < n - k; i ++ )
        if (f[i - 1] >= k && g[i + 1] >= k)
            res.push_back(i);
    return res;
}

int main(){
    vector<int> nums = {388589,17165,726687,401298,600033,537254,301052,151069,399955};
    int k;
    cin >> k;
    vector<int> res = goodIndices(nums,k);
    for(auto num : res)
        cout << num << " ";
    cout << endl;
}
/*
[388589,17165,726687,401298,600033,537254,301052,151069,399955]
4
*/