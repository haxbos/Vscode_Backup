#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i=100; i<=999; ++i){
        int n = i;
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10) * (n%10);
            n /= 10;
        }
        
        if(sum == i){
            cout << sum << endl;
        }
    }
}