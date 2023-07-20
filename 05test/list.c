#include <stdio.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

void Del_X(struct ListNode* head, int x){
    struct ListNode* p;
    if(head == NULL || head->next == NULL)
        return;
    if(head->next->data == x){
        p = head->next;
        head->next = p->next;
        free(p);
        Del_X(head, x);
    }
    else
        Del_X(head->next, x);
}

void buildList(struct ListNode* head, int* arr, int n){
    struct ListNode* p;
    int i;
    head->data = arr[0];
    head->next = NULL;
    p = head;
    for(i = 1; i < n; i++){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;
        p->data = arr[i];
        p->next = NULL;
    }
}

void Output(struct ListNode* head){
    struct ListNode* p;
    p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int arr[7] = {1, 2, 5, 5, 3, 4, 5};
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    buildList(head, arr, 7);
    Output(head);
    Del_X(head, 3);
    Output(head);
    return 0;
}
