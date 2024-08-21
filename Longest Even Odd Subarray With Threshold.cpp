#include <vector>
#include <algorithm>

class Solution {
public:
    int longestAlternatingSubarray(std::vector<int>& nums, int threshold) {
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int count = 1;
                int j = i;
                while (j < nums.size() - 1) {
                    if (nums[j] % 2 != nums[j + 1] % 2 && nums[j + 1] <= threshold) {
                        count++;
                        j++;
                    } else {
                        break;
                    }
                }
                maxLen = std::max(maxLen, count);
            }
        }

        return maxLen;
    }
};
