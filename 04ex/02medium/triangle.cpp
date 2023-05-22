#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
//     int n = triangle.size();
//     if(n == 1)  return triangle[0][0];
   
//     for(int i=1; i<n; ++i){
//         for(int j=0; j< i+1; ++j){
//             if(j == 0)  triangle[i][j] += triangle[i-1][j];
//             else if(j == i) triangle[i][j] += triangle[i-1][j-1];
//             else    triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
//         }
//     }
//     int res = triangle[n-1][0];
//     for(auto &num : triangle[n-1])
//         res = min(res,num);
   
//     return res;
    int n = triangle.size();
    
    for(int i=n-2; i>=0; --i){
        for(int j=0; j<=i; ++j){
            triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = minimumTotal(triangle);
    cout << res << endl;
}