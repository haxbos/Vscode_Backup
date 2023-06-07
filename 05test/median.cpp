#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> nums(3,0);
    int n = 7;
    while(n--){
        cout << "Enter three numbers: \n";
        for(int i=0; i<3; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        cout << "midian : " << nums[1] << endl;
    }
    return 0;
}