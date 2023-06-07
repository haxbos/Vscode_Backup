#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> spiral(int n){
        vector<vector<int>> res(n, vector<int>(n,0));
        int up = 0, down = n-1, left = 0, right = n-1;

        int num = 1;
        while(num <= n*n){
            for(int i=left; i<=right; ++i) res[up][i] = num++;
            if(++up > down) break;

            for(int i=up; i<=down; ++i)   res[i][right] = num++;
            if(--right < left) break;

            for(int i=right; i>=left; --i)    res[down][i] = num++;
            if(--down < up) break;

            for(int i=down; i>=up; --i) res[i][left] = num++;
            if(++left > right) break;
        }
        return res;
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<vector<int>> res = sol.spiral(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}