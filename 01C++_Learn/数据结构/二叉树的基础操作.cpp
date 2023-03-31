#include<iostream>
#include<vector>
using namespace std;
#include<queue>

struct BiNode{
    int val;
    BiNode *lchild,*rchild;
    BiNode() : val(0), lchild(nullptr), rchild(nullptr) {}
    BiNode(int x) : val(x), lchild(nullptr), rchild(nullptr) {}
    BiNode(int x, BiNode *lchild, BiNode *rchild) : val(x), lchild(lchild), rchild(rchild) {}
};

void CreateTree(BiNode* &root,queue<int>& dp);  //创建二叉树

void preOrder(BiNode* root);    //先序遍历
void inOrder(BiNode* root);     //中序遍历
void postOrder(BiNode* root);   //后序遍历
vector<vector<int>> levelOrder(BiNode*& root);  //层序遍历，一层层的输出

//template<class T> 
BiNode* FindNode(BiNode* &root,int val);    //查找值为val 的结点，找到了返回该节点地址，没找到则返回NULL
int HeightTree(BiNode* root);   //求二叉树的高度(深度)
void FindLeaf(BiNode* &root,vector<BiNode*> &leafnode);    //查找到叶子节点，并输出
int Nodes(BiNode* root);    //计算的二叉树所有节点的个数
int level(BiNode* root,int x,int h);    //查找值为x的节点的深度
void Knodenum(BiNode* root,int h,int &num,int k);   //查找第k层的节点个数，h代表当前节点的层数，num是K层的节点



void CreateTree(BiNode* &root,queue<int>& dp){   //通过队列创建二叉树
    if(dp.empty()) return ;
    int n=dp.front();
    dp.pop();
    if(n==0){   //等于0时，就是空节点
        root=nullptr;
        return;
    }
    else{
        /*
        *1、如果该类没有定义构造函数（由编译器合成默认构造函数）也没有虚函数，
        *   那么class c = new class;将不调用合成的默认构造函数，而class c = new class();则会调用默认构造函数。
        *2、如果该类没有定义构造函数（由编译器合成默认构造函数）但有虚函数，
        *   那么class c = new class;和class c = new class();一样，都会调用默认构造函数。
        *3、如果该类定义了默认构造函数，
        *   那么class c = new class;和class c = new class();一样，都会调用默认构造函数。
        */
        root =new BiNode();
        root->val=n;
        CreateTree(root->lchild,dp);
        CreateTree(root->rchild,dp);
    }
}

void preOrder(BiNode* root){    //前序遍历
    if(root){
        cout<<root->val<<" ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(BiNode* root){    //中序遍历
    if(root!=NULL){        
        inOrder(root->lchild);
        cout<<root->val<<" ";
        inOrder(root->rchild);
    }
}

void postOrder(BiNode* root){    //后序遍历
    if(root){        
        postOrder(root->lchild);        
        postOrder(root->rchild);
        cout<<root->val<<" ";
    }
}

vector<vector<int>> levelOrder(BiNode*& root) {  //层序遍历
    vector<vector<int>> res;
    if(root==NULL)  return res;   
    queue<BiNode*> dp;
    dp.push(root);

    while(!dp.empty()){  
        int n=dp.size();    //获取队列的大小，也就是这一层的节点数
        res.push_back(vector<int> ());
        for(int i=1;i<=n;i++){  //每一次都把这一层的所有节点输出，遍历完这一层的，队列剩下的就是下一层的
            auto p=dp.front();dp.pop();
            res.back().push_back(p->val);
            if(p->lchild)     dp.push(p->lchild);   //把非空的节点加入队列
            if(p->rchild)    dp.push(p->rchild);
        }
    }
    return res;
}

/*
1、当root==NULL,    return NULL;
2、当root->val==num return root;
3、当root->val!=num    则先去左子树中找,FindNode(root->lchild,num);
4、以上都不满足，则去右子树找
*/
BiNode* FindNode(BiNode* &root,int num){
    BiNode* p;
    if(!root)   return NULL;
    else if (root->val==num)    return root;
    else{
        
        p=FindNode(root->lchild,num);
        if(p){
            return p;
        }
        else{
            return FindNode(root->rchild,num);
        }
    }
}

int HeightTree(BiNode* root){
    if(!root)   return 0;
    return max(HeightTree(root->lchild),HeightTree(root->rchild))+1;
}

/*
找到左右子节点都为空的节点
*/
void FindLeaf(BiNode* &root,vector<BiNode*> &leafnode){
    if(root){
        if(!root->lchild && !root->rchild){
            leafnode.push_back(root);
            return;
        }
        if(root->lchild)    FindLeaf(root->lchild,leafnode);
        if(root->rchild)    FindLeaf(root->rchild,leafnode);
    }
}

int Nodes(BiNode* root){    //计算二叉树所有节点的个数
    if(root==NULL)  return 0;
    return Nodes(root->lchild)+Nodes(root->rchild)+1;
}

/*
找到了返回节点高度，没找到，返回0，根节点深度为1
1、root==NULL   return 0
2、root==x  return 1
3、root!=x  level(root->lchild,x,h+1)
4、如果以上都不满足，则level(root->rchild,x,h+1)
*/
int level(BiNode* root,int x,int h){
    if(!root)   return 0;
    else if(root->val==x)    return h;
    else{
        int n=level(root->lchild,x,h+1);
        if(n!=0)
            return n;
        else{
            return level(root->rchild,x,h+1);
        }
    }
}

//层数相等时，num++,层数小于则继续往下找，层数大于什么都不做
void Knodenum(BiNode* root,int h,int &num, int k){
    if(root==NULL)  return  ;
    if(h==k)    num++;
    else if(h<k){
        Knodenum(root->lchild,h+1,num,k);
        Knodenum(root->rchild,h+1,num,k);
    }
}
int main(){
    BiNode* root;
    queue<int> dp;
    vector<int> arr={1,2,4,0,6,0,0,0,3,0,5,0,0};
    for(int i=0;i<arr.size();i++){
        dp.push(arr[i]);
    }
    
    CreateTree(root,dp);
    
    cout<<"preOrder: "<<endl;
    preOrder(root);
    cout<<"\ninOrder: "<<endl;
    inOrder(root);
    cout<<"\npostOrder: "<<endl;
    postOrder(root);
    cout<<"\nlevelOrder:  "<<endl;

    vector<vector<int>> res=levelOrder(root);
    for(auto &ch:res){  //一层一层的输出
        for(auto &num:ch){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    BiNode* findnode;
    findnode=FindNode(root,10);
    if(findnode){
        cout<<"findnode->val="<<findnode->val<<endl;
    }
    else{
        cout<<"This node does not exist in this binary tree! "<<endl;
    }

    int ans=HeightTree(root);
    cout<<"The height of the binary tree is "<<ans<<endl;

    vector<BiNode*> leafnode(dp.size());
    FindLeaf(root,leafnode);
    for(auto& leaf:leafnode){
        cout<<leaf->val<<" ";
    }
    cout<<endl;

    cout<<"The nodes of the binary tree have a total of:"<<Nodes(root)<<endl;

    int leaf=level(root,5,1);
    cout<<leaf<<endl;

    int num=0;
    Knodenum(root,1,num,3);
    cout<<"The number of nodes in the third layer is : "<<num<<endl;

}