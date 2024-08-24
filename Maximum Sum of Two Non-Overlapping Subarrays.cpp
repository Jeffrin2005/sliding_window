#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen) {
        return std::max(maxSum(nums, firstLen, secondLen), maxSum(nums, secondLen, firstLen));
    }

private:
    int maxSum(const std::vector<int>& nums, int len1, int len2) {
        int n = nums.size();
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int maxLen1 = 0, maxTotal = 0;
        for (int i = len1 + len2; i <= n; ++i) {
            maxLen1 = std::max(maxLen1, prefixSum[i - len2] - prefixSum[i - len2 - len1]);
            maxTotal = std::max(maxTotal, maxLen1 + (prefixSum[i] - prefixSum[i - len2]));
        }
        return maxTotal;
    }
};
