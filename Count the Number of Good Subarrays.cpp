// Let's consider an array nums = [2, 3, 2, 2, 4] and analyze what happens as we slide through it:
// Initial State: l = 0, r = 0, freq = {}, pairs = 0
// nums[r] = 2, freq[2] = 0 (before increment)
// No pairs are formed since freq[2] = 0.
// Increment freq[2], now freq[2] = 1.
// 2. Next State: r = 1
// nums[r] = 3, freq[3] = 0 (before increment)
// No pairs are formed since freq[3] = 0.
// Increment freq[3], now freq[3] = 1.
// 3. Next State: r = 2
// nums[r] = 2, freq[2] = 1 (before increment)
// pairs += freq[2] → pairs += 1 because there is one 2 before this point (at index 0).
// Increment freq[2], now freq[2] = 2.
// 4. Next State: r = 3
// nums[r] = 2, freq[2] = 2 (before increment)
// pairs += freq[2] → pairs += 2 because there are two 2s before this point (at indices 0 and 2).
// Increment freq[2], now freq[2] = 3.

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int pairs = 0;
        int l = 0;

        for (int r = 0; r < n;r++){
            // Increment the number of pairs with the current nums[r]
            if (freq[nums[r]] > 0){
                pairs += freq[nums[r]];
            }
            freq[nums[r]]++;
            // While the number of pairs is at least k, move the left pointer to try and find smaller subarrays
            while (pairs >= k) {
                count += n - r; // All subarrays starting from l to r and ending at r to n-1 are valid
                freq[nums[l]]--;
                pairs -= freq[nums[l]];
                l++;
            }
        }

        return count;
    }
};
