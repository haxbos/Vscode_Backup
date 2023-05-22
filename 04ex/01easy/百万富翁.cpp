#include <bits/stdc++.h>
using namespace std;

int main(){
    long fw = 0;
    long st = 100000 * 30;
    long num = 1;
    for(int i=1; i<=30; ++i){
        fw += num;
        num *= 2;
    }
    //cout << fw/100 << " " << st;
    printf("%ld %ld\n",fw/100,st);
}