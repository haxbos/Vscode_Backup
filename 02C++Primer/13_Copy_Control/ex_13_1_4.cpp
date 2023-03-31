#include <iostream>
using namespace std;

class Numbered{
public:
    Numbered(){
        mysn = ++unique;
    }

    Numbered(Numbered &s){
        mysn = ++unique;
    }

    int mysn;
    static int unique;
};

int Numbered::unique = 10;

// void f(Numbered s){
//     cout << s.mysn << endl;
// }

void f(const Numbered &s){
    cout << s.mysn << endl;
}

int main(){
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}