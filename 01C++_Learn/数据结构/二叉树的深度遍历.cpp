#include<iostream>
using namespace std;
#include<queue>

struct TreeNode{
    int val;
    TreeNode *left,*right;
};

void CreateTree(TreeNode* root,queue<int>& dp){
    if(!dp.empty()) return ;
    int n=dp.front();dp.pop();
    if(n==0){
        root=NULL;
        return ;
    }
    else{
        root=new TreeNode;
        root->val=n;
        CreateTree(root->left,dp);
        CreateTree(root->right,dp);
    }
}
int maxDepth(TreeNode* root) {
    if(root==NULL)  return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

int main(){
    TreeNode* root;
    queue<int> dp;//={3,9,20,0,0,15,7};
    dp.push(1);
    dp.push(9);
    dp.push(20);
    dp.push(0);
    dp.push(0);
    dp.push(15);
    dp.push(7);
    int res;
    res=maxDepth(root);
    cout<<res<<endl;
}