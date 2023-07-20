#include <iostream>
#include <vector>
using namespace std;

bool checkArray(vector<int> &nums, int k) {
    int n = nums.size(), sum_d = 0;
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++) {
        sum_d += d[i];
        int x = nums[i];
        x += sum_d;
        if (x == 0) continue; // 无需操作
        if (x < 0 || i + k > n) return false; // 无法操作
        sum_d -= x; // 直接加到 sum_d 中
        d[i + k] += x;
    }
    return true;
}

int main(){
    vector<int> nums{2,2,3,1,1,0};
    int k = 3;
    bool flag = checkArray(nums, k);
    cout << flag << endl;
    return 0;
}