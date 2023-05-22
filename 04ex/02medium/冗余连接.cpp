#include <bits/stdc++.h>
using namespace std;

class Solution {
    int p[1005];
public:
    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    int same(int x,int y){
        return find(x) == find(y);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //vector<int> res(2,-1);
        for(int i=0; i<1005; ++i){
            p[i] = i;
        }
        int n = edges.size();

        for(int i=0; i<n; ++i){
            if(same(edges[i][0],edges[i][1])) return edges[i];
            else{
                p[find(edges[i][1])] = find(edges[i][0]);
            }
        }
        return {};
    }
};

int main(){
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    Solution s;
    vector<int> res = s.findRedundantConnection(edges);
    cout << res[0] <<" " << res[1] << endl;

}
