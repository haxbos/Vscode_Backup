#include <bits/stdc++.h>
using namespace std;

/*
给定一个字符串 s，计算 s 的 不同非空子序列 的个数。因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。
字符串的 子序列 是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。

例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是。
*/

//dp 、 滚动数组

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.length();

        //每一个字母的重复子序列个数
        int repeatCount[26] = {0};
        
        //当前不同子序列个数，开始等于1是空字符
        int curAns = 1;

        //添加当前字母时的新增子序列个数
        int newCount = 0;

        for(int i=0; i<n; ++i){
            //因为新增的个数 = 上次的总个数
            newCount = curAns;

            //dp[i] = dp[i-1] + newCount - repeatCount;
            //这里括号中最后 + mod，是为了防止前面相减为负数
            curAns = ((curAns + newCount)%mod - (repeatCount[s[i]-'a'] % mod) + mod)%mod;

            //下一次添加相同字母时，重复的子序列个数即为 当前字母新增的子序列个数
            repeatCount[s[i]-'a'] = newCount;
        }

        //最后记得把 空字符 去掉
        return curAns - 1;
    
    }
};

int main(){
    string s = "asdfasdgadfgdafg";
    Solution solve;
    int res = solve.distinctSubseqII(s);
    cout << res << endl;
}