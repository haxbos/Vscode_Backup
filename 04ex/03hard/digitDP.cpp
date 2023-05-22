#include <bits/stdc++.h>
using namespace std;

int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int size = digits.size();
    string s = to_string(n);
    int len = s.length();
    vector<int> arr(size,0);
    for(int i=0; i<size; ++i){
        arr[i] = stoi(digits[i]);
    }

    int res = 0;
    for(int i=1; i<len; ++i){    //位数小于n的
        res += pow(size,i);
        //cout <<"1 :" << res << endl;
    }

    for(int i=0; i<len; ++i){
        int flag = 1;
        for(int k=0; k<size; ++k){
            if(arr[k] < s[i] - '0'){
                res += pow(size,len-i-1);
            }
            else{
                if(arr[k] == s[i] - '0')    flag = 0;
                break;
            }  
        }
        if(flag)   return   res; 
    }
    return ++res;
}

int main(){
    vector<string> digits = {"1","3","5","7","9"};
    int n = 13579;
    int res = atMostNGivenDigitSet(digits,n);
    cout << res << endl;
}