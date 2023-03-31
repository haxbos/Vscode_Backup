#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void test01(){
    ostream_iterator<int> iter(cout, " ");
    vector<int> arr = {1,2,3,4,5};

    copy(arr.begin(),arr.end(),iter);
}

// void test02(){
//     ofstream ofs("str_in.txt");
//     ostream_iterator<string> iter(ofs," ");

// }
int main(){
    test01();
    //test02();
}