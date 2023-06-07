#include <iostream>
#include <vector>
#include <exception>
using namespace std;

double division(const double &a, const double &b){
    if(b == 0) 
        throw "Division by zero condition!";
    return a/b;
}

int main(){
    double dividend, divisor, result = 0;
    int n = 9;
    while(n--){
        cout << "Enter dividend: ";
        cin >> dividend;
        cout << "Enter divisor: ";
        cin >> divisor;
        try{
            result = division(dividend, divisor);
            cout << "Result: " << result << endl;
        }
        catch(const char* msg){
            cerr << msg << endl;
        }
    }
    return 0;
}