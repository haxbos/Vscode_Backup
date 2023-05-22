#include <iostream>
using namespace std;

class Test{
public:
    static const int num = 223;
};

int main(){
    Test *t;
    cout << t->num << endl;
}