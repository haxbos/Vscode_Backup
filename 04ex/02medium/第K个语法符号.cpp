#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
    string s = "0";
    if(k == 0)  return 0;
    for(int i=2; i<n; ++i){
        string next = "";
        for(int j=0; j<pow(2,i-1); ++j){
            if(s[j] == '0')     next += "01";
            else next += "10";
            if(i == n-1 && j == (k-1)/2){
                if((k-1) ^ 1) return next[k-1] - '0';
                else return next[k-2] - '0';
            }
        }
        s = next;
    }
    return 0;
}

int main(){
    int n = 2, k =2;

    int res = kthGrammar(n,k);
    cout << res << endl;
}