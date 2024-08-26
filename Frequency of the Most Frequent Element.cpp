class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int l = 0; 
        int maxFreq = 1;
        for(int r = 0; r < nums.size(); ++r) { 
            total += nums[r];// Current window size is (r - l + 1)
            // Target sum if all were nums[r] is nums[r] * (r - l + 1)
            while (nums[r] * (long long)(r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            } maxFreq = max(maxFreq, r - l + 1);
        }   return maxFreq;
    }
};// WHY TOTAL + K ?
// Consider nums = [1, 2, 4] and k = 5.
// For r = 2 (where nums[r] = 4):
// Suppose l = 0, so the window is [1, 2, 4].
// total for this window is 1 + 2 + 4 = 7.
// The desired sum to make all elements equal to 4 is 4 * 3 = 12.
// total + k is 7 + 5 = 12.
// Here, 12 (desired sum) is equal to 12 (maximum achievable sum with k increments), meaning it's just possible to make all elements 4 if every increment is used perfectly. If the desired sum were any higher (say if k were smaller or nums[r] were larger), you would need to adjust the window by moving l to reduce the number of elements, thereby reducing the required sum to a more achievable level.
