#include <vector>
using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& nums) {
        if (!nums.empty()) {
            vector<int> buffer(nums.size());
            MergeSortImpl(nums, buffer, 0, nums.size() - 1);
        }
    }

    void MergeSortImpl(vector<int>& nums, vector<int>& buffer, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            MergeSortImpl(nums, buffer, l, m);
            MergeSortImpl(nums, buffer, m + 1, r);

            int k = l;
            for (int i = l, j = m + 1; i <= m || j <= r; ) {
                if (j > r || (i <= m && nums[i] < nums[j])) {
                    buffer[k] = nums[i];
                    ++i;
                }
                else {
                    buffer[k] = nums[j];
                    ++j;
                }
                ++k;
            }
            for (int i = l; i <= r; ++i) {
                nums[i] = buffer[i];
            }
        }
    }
};
