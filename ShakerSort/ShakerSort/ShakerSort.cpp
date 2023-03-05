#include <vector>

class ShakeSort {
public:
    void Sort(std::vector<int>& nums) {
        if (nums.empty()) { return; }
        int left = 0;
        int right = nums.size() - 1;
        int tmp = 0;
        while (left <= right) {
            for (int i = right; i > left; i--) {
                if (nums[i] < nums[i - 1]) {
                    tmp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = tmp;
                }
            }
            left++;

            for (int i = left; i < right; i++) {
                if (nums[i] > nums[i + 1]) {
                    tmp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = tmp;
                }
            }
            right--;
        }
     }
};
