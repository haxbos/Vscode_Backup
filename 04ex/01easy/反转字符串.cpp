#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    int left = 0, right = 0, flag = 0;
    int n = s.size();

    while(flag < n){
        while(flag < n && s[flag] != ' ') ++flag;
        
        right = flag - 1;

        cout << flag << " " << left << " " << right << endl;

        for(; left < right; ++left, --right){
            swap(s[left],s[right]);
        }

        left = flag + 1;
        flag = left;
    }
    return s;
}

int main(){
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
    return 0;
}