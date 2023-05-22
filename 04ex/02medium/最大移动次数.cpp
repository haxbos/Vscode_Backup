#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        //vector<vector<int>> flag(m,vector<int>(n));
        queue<int> q;
        for(int i=0; i<m; ++i){
            q.push(i);
        }
        
        for(int j=0; j<n-1; ++j){
            int size = q.size();
            vector<int> flag(m,0);
            for(int num = 0; num < size; ++num){      
                int i = q.front();
                q.pop();         
                int col = j + 1;
                
                for(int row=i-1; row<=i+1; ++row){
                    // if(row >= 0 && row < m && flag[row][col] == 0 && grid[row][col] > grid[i][j]){
                    //     flag[row][col] = 1;
                    //     q.push(row);
                    // }
                    if(row >= 0 && row < m && flag[row] == 0 && grid[row][col] > grid[i][j]){
                        flag[row] = 1;
                        q.push(row);
                    }
                }
            }
            if(q.empty()) return j;
        }
        return n - 1;
    }
};

int main(){
    
}