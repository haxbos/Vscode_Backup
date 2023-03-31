#include <iostream>
#include <vector>
using namespace std;

//ex10.20
int main(){
    int i = 7;
    auto check_and_decrement = [&i]() { return i > 0 ? --i : i; };
    cout << "ex10.21: ";
    while(check_and_decrement())
        cout << i << " ";
    cout << i << endl;
}