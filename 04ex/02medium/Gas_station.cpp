#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int curSum = 0, total = 0, start = 0;
    for(int i=0; i<n; ++i){
        total += gas[i] - cost[i];
        curSum += gas[i] - cost[i];
        if(curSum  < 0){
            curSum = 0;
            start = i + 1;
        }
    }    
    if(total < 0) return -1;
    return start;
}

int main(){
    // vector<int> gas = {1,2,3,4,5};
    // vector<int> cost = {3,4,5,1,2};
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}