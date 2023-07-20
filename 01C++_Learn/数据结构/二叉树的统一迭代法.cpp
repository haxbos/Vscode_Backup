#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Treenode{
    Treenode* left, *right;
    int val;
    Treenode():val(0),left(nullptr),right(nullptr){}
};

void BtreeBuild(Treenode* root, vector<int> &val){

}

//前序遍历
vector<int> preOrder(Treenode* root){
    stack<Treenode*> st;
    vector<int> res;
    if(root) st.emplace(root);

    while(!st.empty()){
        Treenode* node = st.top();
        st.pop();
        if(node != nullptr){
            if(node->right) st.emplace(node->right);
            if(node->left) st.emplace(node->left);

            st.emplace(node);
            st.emplace(nullptr);
        }
        else{
            node = st.top();
            res.emplace_back(node->val);
            st.pop();
        }
    }
    return res;
}

int main(){
    vector<int> val{};
}