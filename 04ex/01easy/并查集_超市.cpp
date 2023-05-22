#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using Pii = pair<int,int>;  //利润、时间

const int MAX_N = 10010;
int N;

int main(){
    
    while(cin >> N){
        vector<Pii> arr(N);
        for(int i=0; i<N; ++i)  cin >> arr[i].second >> arr[i].first;

        sort(arr.begin(),arr.end());

        priority_queue<int,vector<int>,greater<int>> hash;
        for(auto &[l,r] : arr){
            hash.push(r);
            if(hash.size() > l) hash.pop();
        }

        int res = 0;
        while(hash.size())  res += hash.top(),hash.pop();
        
        cout << res << endl;
    }
}

/*
5
3 2
65 1
61 3
60 2
86 1
*/