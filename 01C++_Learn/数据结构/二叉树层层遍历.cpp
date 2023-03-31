#include<iostream>
using namespace std;
#include<queue>

int n,m;
struct TreeNode{
    int val;
    TreeNode *lchild, *rchild;
};

/*
//顶部开始逐层打印二叉树结点
void level_print(binary_tree_node*root)
{
	if (root == NULL)
		return;
	queue<binary_tree_node*> q;
	q.push(root);
	while (!q.empty())
	{
		binary_tree_node*temp = q.front();
		cout << temp->data << " ";
		if (temp->left_child != NULL)
			q.push(temp->left_child);
		if (temp->right_child != NULL)
			q.push(temp->right_child);
		q.pop();
	}
}
*/

//从顶部开始，层层创建二叉树
void levelCreate(TreeNode* &head,int n){
    int i=1;
    queue<TreeNode*> dp; 
    head=new TreeNode;
    dp.push(head);
    while(i<=n){
        TreeNode* root=new TreeNode;
        root=dp.front();
        root->val=i;
         dp.pop();
        dp.push(root->lchild);
        dp.push(root->rchild); 
        i++;
    }
    // while(!dp.empty()){
    //     TreeNode *p;
    //     p=dp.front();
    //     p=NULL;
    //     dp.pop();
    // }
}
//先序遍历
void preOrder(TreeNode* &root){
    if(root!=NULL){
        cout<<root->val<<" ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
int main(){
    cin>>n;
    TreeNode *head;
    levelCreate(head,n);
    preOrder(head);

}   