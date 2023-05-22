#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
vector<PII> a;

//clear 的作用并不是把容器中的内容全部清0
//而是，把容器的 size  设置为 0 ，而容器中的数据实际上仍然存在
int main(){
    int n,m;
    cin>>n>>m;
    a.push_back({n,m});

    cout <<"before size : " << a.size() << endl;
    cout<<a[0].first<<" "<<a[0].second<<endl;

    a.clear();

    cout <<"after size : " <<  a.size() << endl;
    cout<<a[0].first<<" "<<a[0].second<<endl;
}