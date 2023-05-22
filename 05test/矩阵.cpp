#include <bits/stdc++.h>
using namespace std;

void spiralOrder(vector<vector<int>>& matrix, int n) {
    vector<int> res;
    int up = 0;
    int down = matrix.size()-1;
    int left = 0;
    int right = matrix[0].size()-1;
    int num = 1;
    
    while(num <= n){
        for(int i=left; i<=right; ++i)  matrix[up][i] = num;
        if(++up > down) break;

        for(int i=up; i<=down; ++i) matrix[i][right] = num;
        if(--right < left)  break;

        for(int i=right; i>= left; --i) matrix[down][i] = num;
        if(--down < up) break;
        
        for(int i=down; i>=up; --i) matrix[i][left] = num;
        if(++left > right)  break;

        ++num;
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<vector<int>> arr(n,vector<int>(n,0));
        spiralOrder(arr,n);
        for(auto &nums : arr){
            for(auto &num : nums){
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
}