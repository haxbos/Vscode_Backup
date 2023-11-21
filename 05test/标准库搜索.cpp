#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void testLowerBound(vector<int>& arr, int num){
    //返回一个迭代器，指向第一个不小于 n 的元素 
    auto pos = lower_bound(arr.begin(), arr.end(), num);
    int idx = distance(arr.begin(), pos);    //求两个迭代器之间的距离
    cout << "*pos = " << *pos << " idx : " << idx << endl;
}

//查找降序数组中第一个小于或等于num的数
void find_first_less_equal(vector<int>& arr, int num) {
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto &num : arr) cout << num << " ";
    cout << endl;

    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= num) right = mid - 1;
        else left = mid + 1;
    }
    cout << "first less equal than " << num << " is " << arr[left] << endl;
}

void find_first_less(vector<int>& arr, int num) {
    sort(arr.begin(), arr.end(), greater());
    for(auto &num : arr) cout << num << " ";
    cout << endl;

    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
   cout << "first less than " << num << " is " << arr[left] << endl;
}

//建议使用有序数组，不然可能查找不到数据
int main(){
    vector<int> arr = {1,2,2,5,7,9,2,4,5,6};
    sort(arr.begin(),arr.end());

    for(auto &num : arr) cout << num << " ";
    cout << endl;

    testLowerBound(arr, 9);
    cout << "------------------------" << endl;
    find_first_less_equal(arr, 5);
}