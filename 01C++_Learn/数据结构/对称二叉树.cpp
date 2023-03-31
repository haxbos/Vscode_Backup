#include<iostream>
#include<vector>
using namespace std;
#include<queue>

struct TreeNode{
    int val;
    TreeNode* left,*right;
};

void CreateTree(TreeNode* root){

}

bool isSymmetric(TreeNode* root) {
   if(!root->left && !root->right)  return true;
   return check(root->left,root->right);
}
bool check(TreeNode *lchild,TreeNode* rchild){
    queue<TreeNode*> dp;    //用队列存储左右子树的对称节点，即队列中相邻两个数据相等，否则不对称
    dp.push(lchild);
    dp.push(rchild);
    TreeNode *p,*v;
    while(!dp.empty()){
        p=dp.front();dp.pop();
        v=dp.front();dp.pop();
        if(!p && !v)    continue;   //两者都为空，直接下一组数据
        if((!p || !v) || p->val!=v->val)    return false;   //一个为空，或值不相等，则不对称
        else{
            dp.push(p->left);
            dp.push(v->right);

            dp.push(p->right);
            dp.push(v->left);
        }
    }
    return true;
}
int main(){
    TreeNode* root;

}