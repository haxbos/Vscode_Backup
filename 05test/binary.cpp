#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int> &arr, int target){
    int left = 0, right = arr.size()-1;

    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] < target)   left = mid + 1;
        else if(arr[mid] > target) right = mid - 1;
        else    return mid;       
    }
    return -1;
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,8,9,10,11};
    int target = 11;
    
    int res = binary_search(arr,target);
    cout << res << endl;
    return 0;
}
