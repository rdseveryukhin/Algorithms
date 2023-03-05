#include <vector>
using namespace std;

class QuickSort {
public:
    void Sort(vector<int>& nums) {
        if (!nums.empty()) {
            QuickSortImpl(nums, 0, nums.size() - 1);
        }
    }

    void QuickSortImpl(vector<int>& nums, int l, int r) {
        if (l < r) {
            int q = Partition(nums, l, r);
            QuickSortImpl(nums, l, q - 1);
            QuickSortImpl(nums, q + 1, r);
        }
    }

    int Partition(vector<int>& nums, int l, int r) {
        int x = nums[r];
        int less = l;

        for (int i = l; i < r; ++i) {
            if (nums[i] <= x) {
                swap(nums[i], nums[less]);
                ++less;
            }
        }
        swap(nums[less], nums[r]);
        return less;
    }
};

