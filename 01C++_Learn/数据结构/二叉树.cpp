#include<iostream>
#include<deque>
using namespace std;
#include<string>

// typedef struct BinaryNode{
//     int val;
//     BinaryNode *left,*right;
// };
class Node {
public:
    string ch;
    Node* left;
    Node* right;
    Node() {}
    Node(string _ch) {
        ch = _ch;
    }
    Node(string _ch, Node* _left,Node* _right) {
        ch = _ch;
        right=_right;
        left=_left;
    }
};
//创建二叉树
void CreateBiNode(Node* T,deque<string>& nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]=="#"){
            T=NULL;
            nums.pop_front();
        }            
        else{
            T=new Node(nums[i]);
            nums.pop_front();
            CreateBiNode(T->left,nums);
            CreateBiNode(T->right,nums);
        }
    }
}

//先序遍历二叉树
void PerorderTraverse(Node* T){
    if(T){
        cout<<T->ch<<" ";
        PerorderTraverse(T->left);
        PerorderTraverse(T->right);
    }
    else
        cout<<" ";

}
int main(){
    Node* T;
    deque<string> nums={"a","#","c","d","e","#","g","h"};

    //{1,NULL,3,2,4,NULL,5,6};
    CreateBiNode(T,nums);
    PerorderTraverse(T);
}