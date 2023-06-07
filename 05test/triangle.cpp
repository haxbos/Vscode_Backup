#include <iostream>
#include <vector>
using namespace std;

int judge(vector<int>& nums){
    // 0: Not a triangle
    if(nums[0] + nums[1] <= nums[2]) return 0;
    // 1: Equilateral triangle   
    if(nums[0] == nums[1] && nums[1] == nums[2]) return 1;
    // 2: Isosceles triangle
    if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return 2; 
    // 3: Normal triangle
    return 3; 
}

int main(){
    vector<int> nums(3,0);
    int n = 12;
    while(n--){
        cout << "Enter three sides of a triangle: \n";
        for(int i=0; i<3; ++i){
            cin >> nums[i];
        }
        vector<string> res = {"Not a triangle", "Equilateral triangle", 
        "Isosceles triangle", "Normal triangle"};
        cout << res[judge(nums)] << endl;
    }
    
    return 0;
}