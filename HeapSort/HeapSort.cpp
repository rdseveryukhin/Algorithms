#include <iostream>
#include <vector>
using namespace std;

vector<int> heapSort(vector<int>& nums) {
    build_heap(nums);
    int end = nums.size() - 1;

    while (end >= 0) {
        swap(nums[0], nums[end]);
        sink(nums, 0, end);
        end -= 1;
    }
    return nums;
}

void build_heap(vector<int>& nums) {
    int index = nums.size() / 2 - 1;
    while (index >= 0) {
        sink(nums, index, nums.size());
        index--;
    }
}

void sink(vector<int>& nums, int i, int max) {
    int big_index, childl, childr;
    while (i < max) {
        big_index = i;
        childl = 2 * i + 1;
        childr = childl + 1;
        if (childl < max && nums[childl] > nums[big_index]) {
            big_index = childl;
        }
        if (childr < max && nums[childr] > nums[big_index]) {
            big_index = childr;
        }
        if (big_index == i) return;
        swap(nums[i], nums[big_index]);
        i = big_index;
    }
}

