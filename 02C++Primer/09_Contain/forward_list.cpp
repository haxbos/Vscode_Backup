#include <iostream>
#include <forward_list>
using namespace std;

void test_plusplus(){
    forward_list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.before_begin();
    ++it;
    while(it != lst.end()){
        if(!(*it++ & 1))  cout << *it << " ";
    }
}

int main(){
    test_plusplus();
}