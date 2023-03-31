#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*  将容器内的元素进行反转
reverse(iterator beg,iterator end);
*/

class PrintVector{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};
int main(){
    vector<int> v={1,2,3,4,5,6,7,8};
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),PrintVector());   
}