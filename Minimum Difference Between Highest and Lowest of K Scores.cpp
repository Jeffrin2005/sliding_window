class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int minDiff = INT_MAX; 
        int l = 0;
        int r = k - 1; // r is initialized to the end of the first window of size k.
        // Slide the window across the array until the right pointer reaches the end.
        while (r < nums.size()){
            int currentDiff = nums[r] - nums[l]; // Difference between max and min in the current window.
            minDiff = min(minDiff, currentDiff); // Update the minimum difference found.
            // Move the window one step to the right.
            l++;
            r++;
        }
        
        return minDiff; 
    }
};


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; // If k is 1, the difference is always 0.
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        int minDiff = INT_MAX;
        
        // Use a sliding window of size k to find the minimum difference.
        for (int i = 0; i <= n - k;i++) {
            int currentDiff = nums[i + k - 1] - nums[i]; // Difference between max and min in the current window.
            minDiff = min(minDiff, currentDiff); 
        }
        
        return minDiff; 
    }
};
