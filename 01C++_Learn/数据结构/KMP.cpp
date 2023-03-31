#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<algorithm>

vector<int> make_next(string T){
    vector<int> next(T.length(),0);
    int i=0,j=-1;
    next[0]=-1;
    int len=T.length();
    while(i<len){
        if(j==-1 || T[i]==T[j]){
            next[++i]=++j;
        }
        else{
            j=next[j];
        }
    }
    return next;
}

int KMP(string S,string T,vector<int>& next){
    int i=0,j=0;
    while(j<T.length() && i<S.length()){
        if(j==-1 || S[i]==T[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==T.length())
        return i-j;
    return -1;

}
void PrintNext(int val){
    cout<<val<<" ";
}
int main(){
    string S="bbabcabcd";
    string T="babca";
    vector<int> next(T.length(),0);
    next=make_next(T);
    for_each(next.begin(),next.end(),PrintNext);
    cout<<endl;

    int res=KMP(S,T,next);
    cout<<res;
    return 0;
}