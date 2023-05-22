#include <iostream>
using namespace std;
#include <vector>

int main(){
    vector<int> arr={1,2,3,4,5,6};
    for(vector<int>::iterator it=arr.begin(); it<arr.end(); ++it){
        cout << *it << " ";
    }
}