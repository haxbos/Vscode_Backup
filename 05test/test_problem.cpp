#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(4);
    v[1]=1;
    v[2]=2;
    int *p=&v[3];
    for(int i = 0;i<100;i++) v.push_back(i);
    v[3]=300;
    *p=400;
    cout<< v[3] <<" " << v[4] << " " <<  *p<<endl;
}