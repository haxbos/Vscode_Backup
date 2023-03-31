#include<iostream>
#include<list>
using namespace std;
#include<vector>

template<class Container>
void removeEveringItem(Container& lst){
    auto itr=lst.begin();
    while(itr!=lst.end()){
        itr=lst.erase(itr);
        if(itr!=lst.end())
            ++itr;
    }
}
int main(){
    //list<int> lst={1,2,3,4,5,6,7,8,9};
    vector<int> lst={1,2,3,4,5,6,7,8,9};
    removeEveringItem(lst);
    auto itr=lst.begin();
    while(itr!=lst.end()){
        cout<<*itr++<<" ";
    }
}