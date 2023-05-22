#include <bits/stdc++.h>
using namespace std;

int main(){
    list<int> lst = {5,3,4,4,7,3,6,11,8,5,11};
    int num = 0;

    for(auto it = lst.begin(); it!=lst.end();){
        if(num > *it){
            num = *it;
            it=lst.erase(it);
        }
        else{
            num = *it;
            ++it;
        }
    }

    cout << endl;
    for(auto it : lst)  cout << it << " ";
}