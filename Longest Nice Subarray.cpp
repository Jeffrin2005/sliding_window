#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 1; // Minimum length is 1 since single element subarrays are always nice
        int l = 0; // Left pointer for the sliding window
        int currentOr = 0; // To keep track of the OR of all elements in the current window

        for (int r = 0; r < nums.size(); ++r) {
            // Move the left pointer to ensure the subarray is nice
            while ((currentOr & nums[r]) != 0) {
                currentOr ^= nums[l]; // Remove nums[l] from currentOr
                l++; // Shrink the window from the left
            }

            // Include nums[r] in the currentOr
            currentOr |= nums[r];
            // Update the maximum length found
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
