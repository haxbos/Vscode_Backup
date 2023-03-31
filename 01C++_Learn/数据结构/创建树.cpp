#include<iostream>
using namespace std;
#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void CreateTree(TreeNode* &head,queue<int>& dp){
    if(dp.size()==0)    return ;
    int ch=dp.front();
    dp.pop();
    if(ch==0){
        return;
    }
    else{
        head=new TreeNode;
        head->val=ch;
        CreateTree(head->left,dp);
        CreateTree(head->right,dp);
    }
}

void inOrder(TreeNode* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

int main(){
    queue<int> dp;//{1,NULL,2,3};
    // dp.push(1);
    // dp.push(0);
    // dp.push(2);
    // dp.push(3);
    dp.push(1);
    dp.push(2);
    dp.push(4);
    dp.push(0);
    dp.push(6);
    dp.push(0);
    dp.push(0);
    dp.push(0);
    dp.push(3);
    dp.push(0);
    dp.push(5);
    dp.push(0);
    dp.push(0);
    TreeNode* head;
    CreateTree(head,dp);
    inOrder(head);
}
/*
ABC  DE G  F   
A B C D E G F 
C B E G D F A 
C B E G D F A 
*/

