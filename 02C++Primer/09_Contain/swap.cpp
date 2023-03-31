#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*(array 使用swap函数进行交换时，是真的交换元素，所以时间非常量级，也不遵循下述规则）
  使用swap 交换函数，交换的是容器的内部数据结构，实际上元素并没有被移动，
  所以交换可以在常量级时间内完成，而且
  原来指向该元素的指针、引用、迭代器等，在交换后还是指向该元素（string 除外）*/
void test_vector(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {9,8,7,6,5,4};

    auto it = arr1.begin() + 3;
    cout << "it : " << *it << endl;

    arr1.swap(arr2);

    cout << "arr1 : " << endl;
    for(auto num : arr1)   cout << num << " ";
    cout << endl;
    cout << "arr2 : " << endl;
    for(auto num : arr2)   cout << num << " ";
    cout << endl;
    cout << "it : " << *it << endl;
}

void test_string(){
    string s1 = "abcde";
    string s2 = "123456";

    auto it = s1.begin() + 3;
    cout << "it : " << *it << endl;

    s1.swap(s2);
    cout << s1 << endl;
    cout << s2 << endl;

    cout << "it : " << *it << endl;
}

int main(){
    //test_vector();
    test_string();
}