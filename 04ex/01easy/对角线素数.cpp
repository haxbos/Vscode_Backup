#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int num)
    {
        if(num==1||num==4) 
          return 0;
        if(num==2||num==3)
          return 1;
        if(num %6!= 1&&num %6!=5)
          return 0 ;
        int tmp =sqrt(num);
        for(int i=5;i<=tmp;i+=6)      
          if(num%i==0||num%(i+2)==0)  
             return 0 ;
        return 1;
    } 

    // bool isPrime(int num) {
    //     if(num == 1) return false;
    //     if(num == 2) return true;
    //     if(num % 2 == 0) return false;
    //     //q:为什么这里是i<=sqrt(num)而不是i<=num/2?
    //     //a:因为如果num是合数，那么num的最小质因子一定不会大于sqrt(num)
    //     //q:sqrt函数作用是什么？
    //     //a:求平方根
    //     for(int i = 3; i <= num; i += 2) {
    //         if(num % i == 0) return false;
    //     }
    //     return true;
    // }   
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int Max = 0;
        for(int i=0; i<n; ++i){
            if(isPrime(nums[i][i]))
                Max = max(Max, nums[i][i]);
            
            if(isPrime(nums[i][n - i - 1]))
                Max = max(Max, nums[i][n - i -1]);
        }
        return Max;
    }
};

int main()
{
    vector<vector<int>> nums = {{1,2,3,4,985},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,2,20},{21,22,23,24,883}};
    
    Solution s;
    cout << s.diagonalPrime(nums) << endl;
    return 0;
}