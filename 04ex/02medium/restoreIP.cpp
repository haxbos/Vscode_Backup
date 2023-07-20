#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        string path = "";
        string str = "";
        function<bool(int,int)> checkIP = [&](int l, int r)->bool{
            if(r - l  > 2 || (r - l != 0 && s[l] == '0')) return false;
            int num = stoi(s.substr(l, r-l+1));
            if(num >= 0 && num <= 255)  return true;
            return false;
        };

        function<void(int, int)> backtracking = [&](int num, int idx)->void{
            if(num == 4){
                res.emplace_back(path);
                return;
            }

            for(int i=idx; i<len; ++i){
                if(num != 3)    str = s.substr(idx,i - idx + 1);
                else str = s.substr(idx, len - idx);

                if(checkIP(idx, i)){
                    path += str;
                    if(num != 3) path += ".";
                    backtracking(num+1, i+1);
                }
                else{
                    break;
                }
                path.erase(path.size() - str.size(), str.size());
            }
        };
        backtracking(0, 0);
        return res;
    }
};

int main(){
    string s = "25525511135";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    for(auto &str : res){
        cout << str << endl;
    }
}