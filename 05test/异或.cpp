#include <iostream>
using namespace std;

int main(){
    int a = 4, b = 5, c = 4;
    cout << (a^b) << std::endl;
    cout << (a^c) << std::endl;
    if(c&1 == 0) cout << "c is even" << endl;
    else cout << "c is odd" << endl;
}