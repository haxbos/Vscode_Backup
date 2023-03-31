#include<iostream>
using namespace std;
#define max_n 27
#include<cstring>

char pre[max_n];
char in[max_n];

struct BiNode{
    char data;
    BiNode* lchild;
    BiNode* rchlid;
};

BiNode* build(int l1,int R1,int l2,int R2){ //返回树的根节点，l1-R1为先序遍历，l2-R2为中序遍历
    if(l1>R1)   return NULL;
    BiNode* root=new BiNode();
    root->data=pre[l1]; //先序遍历的第一个为头节点
    int p=0;
    while(in[p]!=root->data)    p++;    //找到中序遍历的头节点的位置
    int llen=p-l2;  //中序遍历中左子树的长度
    //将他们分割为左右子树
    root->lchild=build(l1+1,l1+llen,l2,p-1);
    root->rchlid=build(l1+llen+1,R1,p+1,R2);
    return root;
}

void postorder(BiNode* root){    //输后序遍历
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchlid);
        cout<<root->data;
    }
}

int main(){
    while(gets(pre)!=NULL){
        gets(in);
        int len=strlen(pre);
        BiNode* root=build(0,len-1,0,len-1);
        postorder(root);
        cout<<endl;
    }
    return 0;
}
/*
ABCDEFG
DCBAEFG
*/