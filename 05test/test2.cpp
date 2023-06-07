#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAXSIZE 10

typedef struct _node{
    int data[MAXSIZE];
    int length;
}Sq;

typedef struct _node2{
    int *data;
    int length;
}Sq2;

void InitList(Sq &L) {
    for(int i=0; i<MAXSIZE; ++i) {
        L.data[i] = 100;
    }
    L.length = MAXSIZE;
}

void test_malloc(){
    Sq2 L;
    L.data = (int *)malloc(sizeof(int)*MAXSIZE);
    // for(int i=0; i<MAXSIZE; ++i) {
    //     L.data[i] = 100;
    // }

    for(int i=0; i<MAXSIZE; ++i) {
        *(L.data+i) = 100;
    }
    L.length = MAXSIZE;

    for(int i=0; i<MAXSIZE; ++i) {
        printf("%d\n", L.data[i]);
    }
    //printf("%d\n", L.data[1]);
    cout << L.data[1] << endl;
    free(L.data);
}

int main(){
    // Sq L;
    // InitList(L);
    // printf("%d\n", L.data[1]);
    // cout << L.data[1] << endl;

    test_malloc();
    return 0;
}