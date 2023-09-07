#include <bits/stdc++.h>
using namespace std;

bool isNumber(string s) {
    bool dotFlag = false, eFlag = false, numFlag = false;

    int k = 0;
    while(k < s.size() && s[k] == ' ') ++k;
    s = s.substr(0,k);
    while(s.back() == ' ') s.pop_back();

    for(int i=0; i<s.size(); ++i){
        if(isdigit(s[i]))
            numFlag = true;
        else if(s[i] == '.' && !dotFlag && !eFlag)
            dotFlag = true;
        else if((s[i] == 'e' || s[i] == 'E') && !eFlag && numFlag){
            eFlag = true;
            numFlag = false;
        }
        else if((s[i] == '+' || s[i] == '-') && (i == 0 || s[i-1] == 'e' || s[i-1] == 'E')){}
        else 
            return false;
    }
    return numFlag;
}

int main(){
    string s = "   ";
    cout << isNumber(s) << endl;
    return 0;
}