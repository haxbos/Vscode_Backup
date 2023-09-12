#include <iostream>
using namespace std;

int strToInt(string str) {
    int res = 0;
    int idx = 0, n = str.size();
    while(idx < n && str[idx] == ' ') ++idx;
    if(idx == n || (str[idx] != '+' && str[idx] != '-' && (str[idx] < '0' || str[idx]  > '9'))) return 0;

    int top = INT_MAX, flag = 1;
    if(str[idx] == '-'){
        top = INT_MIN;
        flag = -1;
    }
    if(str[idx] == '+' || str[idx] == '-') ++idx;

    for(; idx < n; ++idx){
        if(str[idx] >= '0' && str[idx] <= '9'){
            int num = (str[idx] - '0') * flag;
            if((top - num) / 10 >= res)
                res = res * 10 + num;
            else{
                res = top;
                break;
            }
        }
        else break;
    }
    return res;
}

int main(){
    string str = "  -42";
    cout << strToInt(str) << endl;
}