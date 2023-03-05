#include <vector>
#include <algorithm>
using namespace std;

int maxSumOfSubarray(vector<int> arr, int k) {
    int maxSum = 0;
    int runningSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        runningSum += arr[i];

        if (i >= k - 1) {
            maxSum = max(runningSum, maxSum);
            runningSum -= arr[i - (k - 1)];
        }
    }
    return maxSum;
}
