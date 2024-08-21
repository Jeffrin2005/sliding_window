

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        int count = 0;
        int windowSum = 0;
        int targetSum = k * threshold; // Convert average condition to sum for easier comparison

        // Calculate the sum of the first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        // Check the first window
        if (windowSum >= targetSum) {
            count++;
        }

        // Slide the window across the array
        for (int i = k; i < arr.size(); i++) {
            // Update the window sum to include the new element and exclude the old element
            windowSum += arr[i];
            windowSum-= arr[i - k];


            // Check if the current window meets the condition
            if (windowSum >= targetSum) {
                count++;
            }
        }

        return count;
    }
};
