#include <vector>

class BubbleSort {
public:
    void Sort(std::vector<int>& nums) {
        int tmp = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            for (int j = 0; j + 1 < nums.size() - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    tmp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmp;
                }

            }
        }
    }
};

