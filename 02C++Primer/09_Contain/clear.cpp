#include <iostream>
#include <vector>
using namespace std;

void test_clear(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    int n = arr.size();
    cout << "arr.size = " << arr.size() << endl;
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
    arr.clear();
    cout << "arr.size = " << arr.size() << endl;
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
}

int main(){
    test_clear();
}