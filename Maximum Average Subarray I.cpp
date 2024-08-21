\
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currentSum = 0;
        int maxSum = INT_MIN; // Use INT_MIN to handle negative numbers
        int l = 0; // Left pointer of the window
        int r = 0; // Right pointer of the window

        // Use a while loop to manage the right pointer
        while (r < nums.size()) {
            currentSum += nums[r]; // Add the current right element to the sum
            // Check if the window size is exactly k
            if (r - l + 1 == k) {
                maxSum = max(maxSum, currentSum); // Update maxSum if the current window's sum is greater
                currentSum -= nums[l]; // Subtract the element at the left pointer
                l++; // Move the left pointer to the right, shrinking the window from the left side
                r++; // Move the right pointer to the right to expand the window from the right side
            } else {
                r++; // Only move the right pointer if the window size is not yet k
            }
        }

        // Calculate the maximum average
        return static_cast<double>(maxSum) / k;
    }
};
