#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

static int res = 0;

void btreeMaxHeight(const string& preorder, int l1, int r1, 
                    const string& inorder, int l2, int r2, 
                    int height, unordered_map<char, int>& indexMap){
    if(l2 > r2){
        res = max(res, height);
        return;
    }
    int mid = indexMap[preorder[l1]];
    int len = mid - l2;
    btreeMaxHeight(preorder, l1+1, l1+len, inorder, l2, mid-1, height+1, indexMap);
    btreeMaxHeight(preorder, l1+len+1, r1, inorder, mid+1, r2, height+1, indexMap);
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            cout << n << endl;
            continue;
        }
        string preorder, inorder;
        cin >> preorder >> inorder;
        
        unordered_map<char, int> indexMap;
        for (int i = 0; i < n; ++i) {
            indexMap[inorder[i]] = i;
        }

        res = 0;
        btreeMaxHeight(preorder, 0, n-1, inorder, 0, n-1, 0, indexMap);
        cout << res << endl;
    }
}