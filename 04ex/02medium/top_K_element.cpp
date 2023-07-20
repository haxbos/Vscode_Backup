#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
    class myconparsion{
    public:
        bool operator()(pair<int,int>& lhs, pair<int,int>& rhs){
            return lhs.second > rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;
        vector<int> res(k,0);
        for(int& num : nums){
            ++hash[num];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, myconparsion> que;

        for(auto& arr : hash){
            que.push(arr);
            if(que.size() > k){
                que.pop();
            }
        }

        for(int i=0; i<k; ++i){
            res[i] = que.top().first;
            que.pop();
        }
        
        return res;
    }
};

int main(){
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    vector<int> res = sol.topKFrequent(nums, k);
    for(int& num : res)
        cout << num << " ";

}