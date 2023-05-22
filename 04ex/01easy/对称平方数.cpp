#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << 0 << endl;
    for(int i=1; i<=256; ++i){
 
        vector<int> arr;
        int num = i * i;
        int a = -1;
        while(num){
            a = num % 10;
            arr.push_back(a);
            num /= 10;
        }
        vector<int> cp = arr;
        reverse(arr.begin(),arr.end());
        if(arr == cp)   cout << i << endl;
    }
}