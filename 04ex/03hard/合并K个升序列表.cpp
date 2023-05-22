#include <bits/stdc++.h>
using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)  return NULL;
        if(lists[0] == nullptr) return NULL;
        vector<int> arr;
        ListNode *node = new ListNode();
        for(int i=1; i<n; ++i){
            node = lists[i];
            while(node != nullptr){
                arr.emplace_back(node->val);
                node = node->next;
            }
        }
        sort(arr.begin(),arr.end());
        int size = arr.size();
        ListNode root,*head = &root;
        
        for(int i=0; i<size; ++i){
            head->val = arr[i];
            head = head->next;
        }
        return root.next;
    }
};