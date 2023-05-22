#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[26] = {0};
    for(int i=0; i<26; ++i){
        arr[i] = i;
    }
    for(int i=0; i<26; ++i)
        cout << arr[i] << " ";
}