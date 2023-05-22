#include<iostream>
#include<vector>
using namespace std;

/*
dfs,回溯，每一次通过一个bool数组，记录此次排列中某一字母是否被使用
*/

void dfs(vector<string>& res, string s, vector<bool>& flag, string str, int n){
    if(str.length() == n){   //出口，排列长度  == n
        res.push_back(str);
        return;
    }

    for(int i=0;i<s.size();i++){
        if(flag[i] == true)   continue;   //如果该字母被使用，就直接下一个
        flag[i]=true;	//标记使用
        str.push_back(s[i]);
        dfs(res,s,flag,str, n);
        str.pop_back();
        flag[i]=false;	//回溯，解除标记
    }
}   

vector<string> permute(string& s, int n) {
    vector<string> res;
    vector<bool> flag(s.size());     //标记数组，默认赋值是false
    string str;	//存放一次排列
    dfs(res,s,flag,str, n);
    return res;
}

int main(){
    vector<string> res;
    string s;
    cin >> s;
    int n = 0;
    cin >> n;

    res=permute(s, n);

    for(auto &str : res){
        for(auto &alp : str){
            cout<< alp <<" ";
        }
        cout<<endl;
    }
    return 0;
}
