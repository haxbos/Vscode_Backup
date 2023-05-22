#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     //储存每个节点祖宗节点
//     vector<int> p;

//     //查找每个节点的祖宗节点    （模板）
//     int find(int x) {
//         if (p[x] != x) p[x] = find(p[x]);
//         return p[x];
//     }

//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//         int n = vals.size();
//         vector<vector<int>> g(n);

//         for (auto& e: edges) {
//             int a = e[0], b = e[1];
//             g[a].push_back(b);
//             g[b].push_back(a);
//         }

//         //里面存放的是按照权值排序后的节点编号
//         vector<int> q(n);
//         p.resize(n);
//         for (int i = 0; i < n; i ++ ) p[i] = q[i] = i;
//         //按照节点的权值，给节点排序
//         sort(q.begin(), q.end(), [&](int a, int b) {
//             return vals[a] < vals[b];
//         });

//         int res = 0;

//         for (int i = 0; i < n; i ++ ) {
//             int j = i + 1;

//             //找到两个权值相同的节点的位置
//             while (j < n && vals[q[i]] == vals[q[j]]) j ++ ;

//             for (int k = i; k < j; k ++ ) {
//                 int x = q[k];
//                 for (int y: g[x]) {
//                     if (vals[x] >= vals[y])
//                         p[find(x)] = find(y);
//                 }
//             }

//             unordered_map<int, int> hash;
//             for (int k = i; k < j; k ++ )
//                 hash[find(q[k])] ++ ;
//             for (auto& [k, v]: hash)
//                 res += v * (v + 1) / 2;
//             i = j - 1;
//         }

//         return res;
//     }
// };

vector<int> parent;

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int GoodPath (vector<int> &vals, vector<vector<int>> &edges){
    int n = vals.size();
    vector<vector<int>> g(n);
    for(auto &arr : edges){
        int a = arr[0] , b = arr[1];
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector<int> q(n);
    parent.resize(n);

    for(int i=0; i<n; ++i)  parent[i] = q[i] = i;

    sort(q.begin(),q.end(),[&](int &a,int &b){
        return vals[a] < vals[b];
    });

    int res = 0;
    for(int i=0; i<n; ++i){
        int j = i + 1;

        while(j < n && vals[q[i]] == vals[q[j]])  ++j;

        for(int k=i; k<j; ++k){
            int x = q[k];
            for(auto &y : g[x]){
                if(vals[x] >= vals[y])
                    parent[find(x)] = find(y);
            }
        }

        unordered_map<int,int> hash;
        for(int k=i; k<j; ++k)
            ++hash[find(q[k])];
        for(auto &[num,v] : hash)
            res += (v + 1) * v / 2;
        i = j - 1;
    }
    return res;
}

int main(){
    vector<int> vals = {1,3,2,1,3};
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4}};

    int res = GoodPath(vals,edges);

    cout << res << endl;
}