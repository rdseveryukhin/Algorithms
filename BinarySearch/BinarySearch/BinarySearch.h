#include <vector>

class BinarySearch {
public:
    int Search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
    int Search(std::vector<int>& nums, int target, int left, int right) {
        int mid = left + (right - left) / 2;
        if (left > right) {
            return -1;
        }
        else if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return Search(nums, target, left, mid - 1);
        }
        else {
            return Search(nums, target, mid + 1, right);
        }
    }
};
