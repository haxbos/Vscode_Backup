#include<iostream>
using namespace std;

struct BiNode{
    char data;
    BiNode* lchild;
    BiNode* rchild;
};
void preorder(BiNode* &root){    //先序遍历
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);        
    }
}

void inorder(BiNode* &root){ //中序遍历
    if(root!=NULL){
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}

// void postorder(BiNode* &root){
//     if(root!=NULL){
//         postorder(root->lchild);
        
//         postorder(root->rchild);
//         cout<<root->data<<" ";
//     }
// }
 void build(BiNode* &root){
    char ch=getchar();  
    //BiNode* 
    if(ch==' '){
        root=NULL;
        return ;
    }
    else{    
        root=new BiNode;   
        root->data=ch;
        build(root->lchild);
        build(root->rchild);
    }
}
/*
void build(BiNode*& p)
{
    char ch = getchar();//对getchar不了解，建议先百度
    if (ch == ' ')
    {
        p = NULL;
        return;
    }
    else
    {
        p = new BiNode;    
        if (head == NULL)head = p;
        p->data = ch;
        creattree(p->left);
        creattree(p->right);
    }
}
*/
int main(){
    BiNode* root;
    build(root);

    preorder(root);cout<<endl;
    
    inorder(root); cout<<endl;
   
    inorder(root);cout<<endl;
    
    //postorder(root);
}
/*
ABC  DE G  F   
A B C D E G F 
C B E G D F A 
C B E G D F A 

A B C D E G F 
B C D E G F A
B C D E G F A
B C D E G F A
*/