#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
    vector<int> vec = {1,3,7,6,10,12};
    bitset<15> bs;
    for(auto &i : vec) bs.set(i);

    bitset<15> bs2;
    for(int i=0; i<15; ++i)
        bs2[i] = bs[i];

    cout << "bs  : " << bs << endl; 
    cout << "bs2 : " << bs2 << endl; 

}