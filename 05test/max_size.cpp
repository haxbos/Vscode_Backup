#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void vecPrint(){
    vector<int> arr = {1,2,3,4,5,6};
    long long res = arr.max_size();
    cout << res << endl;
    cout << arr.max_size() << endl;
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    arr.push_back(7);
    cout << arr.max_size() << endl;
    cout << arr.capacity() << endl;
}

void strPrint(){
    string s ;
    cout << s.max_size() << endl;
   

    for(int i=1; i<=15; ++i){
        cout << s.size() << " ";
        cout << s.capacity() << " ";
        s += to_string(i);
        cout << endl;
    }
}

int main(){
    //vecPrint();
    strPrint();

}