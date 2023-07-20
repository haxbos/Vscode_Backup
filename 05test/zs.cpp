#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    int target = 4;

    auto it = std::upper_bound(nums.begin(), nums.end(), target);
    int index = std::distance(nums.begin(), it);

    if (it != nums.end()) {
        std::cout << "first " << target << " elemnt : " << *it << std::endl;
        std::cout << "index : " << index << std::endl;
    } else {
        std::cout << "no!" << std::endl;
    }

    return 0;
}