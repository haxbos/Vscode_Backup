#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    bool checkPalin(const string&a, int l, int r){
        while(l < r && a[l] == a[r]){
            ++l;
            --r;
        }
        return l >= r;
    }

    bool check(string a, string b) {
        int len = a.size();
        int l = 0, r = len - 1;
        return checkPalin(a, l, r);
        while(l < r && a[l] == b[r]){
            ++l;
            --r;
        }
        return checkPalin(a, l, r) || checkPalin(b, l, r);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};

int main(){
    Solution s;
    string a = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd";
    string b = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";
    cout << s.checkPalindromeFormation(a,b) << endl;
    return 0;
}