class Solution {
public:
    int longestSubarray(vector<int>& nums) {
          int l = 0, r = 0;
    int zeroCount = 0;
    int maxLength = 0;

    while (r < nums.size()) {
        if (nums[r] == 0) {
            zeroCount++;
        }

        while (zeroCount > 1) {
            if (nums[l] == 0) {
                zeroCount--;
            }
            l++;
        }

        maxLength = max(maxLength, r - l);
        r++;
    }

    return maxLength;
    }
};
