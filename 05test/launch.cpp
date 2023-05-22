#include <bits/stdc++.h>
using namespace std;

 int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int sum1 = accumulate(students.begin(),students.end(),0);   //在指定范围内累加，初始值为第3个参数
    int sum0 = students.size() - sum1;
    
    for(auto &num : sandwiches){
        if(num == 0 && sum0 > 0) --sum0;
        else if(num == 1 && sum1 > 0)    --sum1;
        else break;
    }

    return sum0 + sum1;
}

int main(){
    vector<int> stu = {1,1,1,0,0,1};
    vector<int> sand = {1,0,0,0,1,1};

    int res = countStudents(stu,sand);

    cout << res << endl;
}