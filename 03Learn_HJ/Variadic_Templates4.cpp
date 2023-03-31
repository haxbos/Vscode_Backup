#include <iostream>
#include <algorithm>
using namespace std;

int maximum(int n){
    return n;
}

template<typename...Args>
int maximum(int n, Args... args){
    return max(n,maximum(args...));
}

int main(){
    cout << "maximum = " << maximum(10,102,40,11,3523,9) << endl;
    cout << "max = " << max({10,102,40,11,3523,9}) << endl;
}