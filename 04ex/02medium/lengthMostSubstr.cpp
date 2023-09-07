#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;


// int lengthSubstr(string& s1, string& s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1, vector(m+1,0));
    
//     for(int i=1; i<=n; ++i){
//         for(int j=1; j<=m; ++j){
//             if(s1[i-1] == s2[j-1])
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             else
//                 dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
//         }
//     }
//     return dp[n][m];
// }


int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int n = s1.size();
        int m = s2.size();
        cout << s1 << " " << s2 << endl;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}