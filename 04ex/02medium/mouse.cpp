/*
有两只老鼠和 n 块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。

下标为 i 处的奶酪被吃掉的得分为：

如果第一只老鼠吃掉，则得分为 reward1[i] 。
如果第二只老鼠吃掉，则得分为 reward2[i] 。
给你一个正整数数组 reward1 ，一个正整数数组 reward2 ，和一个非负整数 k 。

请你返回第一只老鼠恰好吃掉 k 块奶酪的情况下，两只老鼠的得分总和最大 得分为多少。

输入：reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
输出：15
解释：这个例子中，第一只老鼠吃掉第 2 和 3 块奶酪（下标从 0 开始），第二只老鼠吃掉第 0 和 1 块奶酪。
总得分为 4 + 4 + 3 + 4 = 15 。
15 是最高得分。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    //错误解答，请重新写
    int maximumScore(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> subt(n,0);
        for(int i = 0; i < n; i++){
            subt[i] = reward1[i] - reward2[i];
        }
        sort(subt.begin(), subt.end());
        int sum = 0;
        for(int i = n-1; i>n-k-1; --i){
            sum += subt[i];
        }

        sum = accumulate(reward2.begin(), reward2.end(), sum);
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> reward1 = {1};
    vector<int> reward2 = {4};
    int k = 1;
    cout << s.maximumScore(reward1, reward2, k) << endl;
    return 0;
}
