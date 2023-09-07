#include <bits/stdc++.h>
using namespace std;

vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    int k = n-1;
    for(int i=0; i<n; ++i){
         while(i < k && ((nums[i]&1) == 0)){
            swap(nums[i], nums[k]);
            --k;
        }
    }
    return nums;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> res = exchange(nums);
    for(auto i:res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}