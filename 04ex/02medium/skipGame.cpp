#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = nums[0], Max = nums[0];
    for(int i=0; i<n;){
        while(i < n && i <= end){
            if(nums[i]+i > Max){
                Max = nums[i] + i;
                start = i;     
            }
            ++i;
        }
        if(i == n) break;
        if(Max == end) return false;
        end = Max;
        
    }
    return true;
}

int main(){
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
    return 0;
}