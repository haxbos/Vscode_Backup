#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<ctime>

/*洗牌，指定范围内的元素，随机调整顺序
random_shuffle(iterator beg,iterator end);
*/

void PrintVector(int val){
    cout<<val<<" ";
}
int main(){
    srand((unsigned int)time(NULL));
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),PrintVector);
}