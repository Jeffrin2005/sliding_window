#include <vector>
#include <climits> // Include for INT_MAX
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); // Length of the array
        int ans = INT_MAX;  // Initialize the answer with a value larger than any possible subarray length

        // Iterate over each possible starting point of the subarray
        for(int i = 0; i < n; ++i) {
            int currOr = 0; // Initialize the current OR sum
            int j = i;      // Start the inner loop index at i

            // Expand the subarray to the right using a while loop
            while(j < n) {
                currOr |= nums[j]; // Update the current OR sum
                // Check if the current OR sum is at least k
                if(currOr >= k) {
                    // Update the answer with the minimum subarray length found so far
                    ans = min(ans, j - i + 1);
                    break; // No need to expand further as we already found a valid subarray
                }
                j++; // Increment j to expand the subarray
            }
        }

        // If the answer is still INT_MAX, it means no valid subarray was found
        if(ans == INT_MAX) ans = -1;
        
        return ans;
    }
};
