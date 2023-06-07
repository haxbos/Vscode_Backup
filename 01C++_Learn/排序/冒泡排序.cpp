#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &input_vec)
{
    if (input_vec.empty() || input_vec.size() == 1)
        return;

    bool swap_flag = true;

    for (int i = 0; i < input_vec.size() - 1 && swap_flag; i++)
    {
        swap_flag = false;
        for (int j = 0; j < input_vec.size() - i - 1; j++)
        {
            if (input_vec[j] > input_vec[j + 1])
            {
                swap_flag = true;
                int temp = input_vec[j];
                input_vec[j] = input_vec[j + 1];
                input_vec[j + 1] = temp;
            }
        }
    }
}

int main(){
    vector<int> arr = {1,3,6,9,8,2,5,4,1,2,3};
    BubbleSort(arr);

    for(auto &num : arr)
        cout << num << " ";
}