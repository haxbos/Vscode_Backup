#include <iostream>
#include <memory>
#include <vector>
using namespace std;

using Vec = std::vector<int>;
std::shared_ptr<int> GetSPtr() {
    //auto elts = {0, 1, 2, 3, 4};
    vector<int> elts = {0, 1, 2, 3, 4};
    std::shared_ptr<Vec> pvec = std::make_shared<Vec>(elts);
    return std::shared_ptr<int>(pvec, &(*pvec)[2]);
}

int main(){
    std::shared_ptr<int> sptr = GetSPtr();
    for (int i = -2; i < 3; ++i) {
        printf("%d\n", sptr.get()[i]);
    }
}
