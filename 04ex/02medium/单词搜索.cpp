#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    int len = word.length();

    function <bool (int, int,int)> dfs = [&](int i,int j,int num){
        if(num == len)  return true;
        if(i < 0 || i >= n || j < 0 || j >= m || word[num] != board[i][j]) return false;

        dfs(i,j-1,num+1);
        dfs(i,j+1,num+1);
        dfs(i-1,j,num+1);
        dfs(i+1,j,num+1);
        return false;
    };
    
    return dfs(0,0,0);
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";

    cout << exist(board,word) << endl;
}