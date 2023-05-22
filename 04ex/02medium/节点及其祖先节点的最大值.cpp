#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res;
public:
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        vector<int> ans = {root->val,root->val};
        dfs(root->left, ans);
        ans[0] = root->val;
        ans[1] = root->val;
        dfs(root->right, ans);
        return res;
    }
    void dfs(TreeNode* root, vector<int> &ans){
        if(!root) return;
        int num = max(abs(root->val - ans[0]), abs(ans[1] - root->val));
        res = max(num , res);
        ans[0] = min(ans[0], root->val);
        ans[1] = min(ans[1], root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};