#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> dp(n,0);
        vector<int> res(m,0);
        string vowel = "aeiou";

        function<bool(string)> isVowel = [&](const string& s){
            const char head = s.front();
            const char tail = s.back();
            if(vowel.find(head) == -1 || vowel.find(tail) == -1)
                return false;
            return true;
        };

        dp[0] = 0;
        
        for(int i=1; i<n; ++i){
            dp[i] = dp[i-1];
            if(isVowel(words[i-1]))
                ++dp[i];
        }

        for(int i=0; i<m; ++i){
            res[i] = dp[queries[i][1]] - dp[queries[i][0]];
            if(isVowel(words[queries[i][1]])) ++res[i];
        }
        return res;
    }
};

int main(){
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    Solution sol;
    vector<int> res = sol.vowelStrings(words,queries);
    for(auto& i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}