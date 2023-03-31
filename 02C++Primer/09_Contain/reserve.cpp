#include <iostream>
#include <vector>
using namespace std;

/*
只有reserve的值超过当前容量时，才会改变vector 的容量
如果小于，则容量不会改变
*/
int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    cout << arr.capacity() << endl;

    arr.reserve(5);
    cout << arr.capacity() << endl;

    arr.reserve(20);
    cout << arr.capacity() << endl;

    //让容器退回多余的容量，使容量大小变为size
    arr.shrink_to_fit();
    cout << arr.capacity() << endl;
}