#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    cin >> n >> k;
    vector<int> arr(k+2,0);
    for(int i=1; i<=k+1; ++i)    cin >> arr[i];

    int res = 0;
    int left = 0,right = 1;
    int len = arr[1];
    int flag = 1;
    while(left < right && right <= k+1){
        int len = 0;
        while(right <= k+1 && len + arr[right] <= n){
            len += arr[right++];
        }
        if(len == 0){
            cout << "No Solution" << endl;
            flag = 0;
            break;
        }
        left = right - 1;
        ++res;
    }
    if(flag)    cout << res - 1 << endl;
}
/*
7 7
1 2 3 4 5 1 6 6
*/