#ifndef ex_13_28
#define ex_13_28

#include <string>
using namespace std;

class TreeNode{
public:
    TreeNode():value(string()),count(new int(1)),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode &node):value(node.value),count(node.count),left(node.left),right(node.right){ ++*count;}
    TreeNode& operator=(const TreeNode& t);

    ~TreeNode();

private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode& t){
    ++*t.count;
    if(--*count == 0){
        delete left;
        delete right;
        delete count;
    }
    value = t.value;
    count = t.count;
    left = t.left;
    right = t.right;
    return *this;
}

TreeNode::~TreeNode(){
    if(--count == 0){
        delete left;
        delete right;
        delete count;
    }
}

class BinStrTree{
public:
    BinStrTree():root(new TreeNode()){}
    BinStrTree(const BinStrTree& bst):root(bst.root){}
    BinStrTree& operator=(const BinStrTree& bst);

    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& bst){
    TreeNode *temp = new TreeNode(*bst.root);
    delete root;
    root = temp;
    return *this;
}
#endif