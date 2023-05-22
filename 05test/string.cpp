#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "abc";
    string s2 = "qwer";

    int len1 = s1.length();
    int len2 = s2.length();

    int i=0, j=0;

    string res = "";

    while(i < len1 || j < len2){
        if(i < len1){
            res += s1[i];
            ++i;
        }
        if(j < len2){
            res += s2[j];
            ++j;
        }
    }

    cout << res << endl;
}