#include <iostream>
using namespace std;

//限定符和引用都被保留
void testConstAndVolatile(){
    const int x = 10;
    decltype(auto) a = x;
    decltype(x) b = x;

    volatile int y = 10;
    decltype(auto) c = y;
    decltype(y) d = y;
}

void testReference(){
    int x = 10;
    int &x_ref = x;
    decltype(auto) a = x_ref;
    decltype(x_ref) b = x_ref;
}
int main(){
    testConstAndVolatile();
    testReference();
    return 0;
}