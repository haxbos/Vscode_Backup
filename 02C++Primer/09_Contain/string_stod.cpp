#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "asdfad-10.25";
    auto d = stod(s1.substr(s1.find_first_of("+-.0123456789")));
    cout << d << endl;
}