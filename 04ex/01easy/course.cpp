#include <bits/stdc++.h>
using namespace std;

//学生人数 40000， 课程数 2500
int courseCount, stuCount;
int stuName[40010];     //每个学生的姓名
int stuClassCt[2510];   //每个学生的课程数
int stuCourse[40010][2510]; //每个学生的课程
int perStuNum[40010];    //每个课程的人数

int main(){
    cin >> courseCount >> stuCount;

    vector<vector<string>> hash(courseCount,vector<string>(stuCount));

    for(int i=0; i<stuCount; ++i){
        cin >> stuName[i] >> stuClassCt[i];
        for(int k=0; k<stuClassCt[i]; ++k){
            cin >> stuCourse[i][k];
            hash[stuCourse[i][k]][perStuNum[stuCourse[i][k]]] = stuName[i];
            ++perStuNum[stuCourse[i][k]];
        }
    }

    

    // for(auto &arr : hash){
    //     cout << arr.first <<" " << arr.second.size() <<endl;
    //     sort(arr.second.begin(),arr.second.end());
    //     for(auto &num : arr.second)  cout << num << endl;
    // }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string.h>
// using namespace std;
// char name[40010][5];
// vector<int> course[2510];
// bool cmp1(int a, int b) {
//     return strcmp(name[a], name[b]) < 0;
// }
// int main() {
//     int n, k;
//     scanf("%d %d", &n, &k);
//     for(int i = 0; i < n; i++) {
//         int cnt, temp;
//         scanf("%s %d", name[i], &cnt);
//         for(int j = 0; j < cnt; j++) {
//             scanf("%d", &temp);
//             course[temp].push_back(i);
//         }
//     }
//     for(int i = 1; i <= k; i++) {
//         printf("%d %d\n", i, course[i].size());
//         sort(course[i].begin(), course[i].end(), cmp1);
//         for(int j = 0; j < course[i].size(); j++)
//             printf("%s\n", name[course[i][j]]);
//     }
//     return 0;
// }