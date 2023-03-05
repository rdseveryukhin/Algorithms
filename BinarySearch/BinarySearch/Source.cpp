#include "BinarySearch.h"
#include <iostream>

int main() {
    std::vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;
    BinarySearch inst;
    //int index = inst.search(nums, target);
    int index = inst.Search(nums, target, 0, nums.size() - 1);

    if (index != -1) {
        std::cout << "Element found at index " << index;
    }
    else {
        std::cout << "Element not found in the array";
    }
    return 0;
}
