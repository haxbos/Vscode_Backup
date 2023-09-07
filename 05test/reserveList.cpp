#include <iostream>
#include <vector>
using namespace std;

struct NodeList{
    int val;
    struct NodeList* next;
};

void buildList(struct NodeList* head, vector<int> nums){
    struct NodeList* p = head;
    for(auto i:nums){
        struct NodeList* node = new struct NodeList;
        node->val = i;
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
}

void resverse(struct NodeList* head){
    struct NodeList* r = head->next;
    struct NodeList* p = head->next->next;
    struct NodeList* q;
    while(p != NULL){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
    r->next = NULL;
}

void printList(struct NodeList* head){
    struct NodeList* p = head->next;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    struct NodeList* head = new struct NodeList;
    head->val = 0;
    head->next = NULL;
    buildList(head, nums);
    printList(head);
    resverse(head);
    printList(head);
}