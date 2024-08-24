

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> count;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < nums.size();right++) {
            count[nums[right]]++;  // Increase the count of the current element
            
            // If the count of any element exceeds k, shrink the window from the left
            while (count[nums[right]] > k) {
                count[nums[left]]--;  // Decrease the count of the element at 'left'
                left++;  // Move the left boundary of the window to the right
            }
            // Update the maximum length of the good subarray
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
