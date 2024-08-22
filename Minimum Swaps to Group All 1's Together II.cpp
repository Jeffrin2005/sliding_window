#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        for(auto&num : nums){
            if (num == 1) totalOnes++;
        }
        // Edge case: if all are 1's or no 1's at all
        if (totalOnes == 0 || totalOnes == nums.size()) return 0;

        // Double the array to simulate circular behavior
        int n = nums.size();
        vector<int> doubledNums(nums.begin(), nums.end());
        doubledNums.insert(doubledNums.end(), nums.begin(), nums.end());
        // Sliding window using two pointers
        int maxOnes = 0, currentOnes = 0;
        int l = 0;
        int  r = 0;
        while(r < 2 * n){
            // Expand the window by moving `r` right
            if (r - l < totalOnes) {
                if (doubledNums[r % n] == 1) currentOnes++;
                r++;
            } else {
                // Contract the window by moving `l` right
                if (doubledNums[l % n] == 1) currentOnes--;
                l++;
            }
            // Update the maximum number of 1's found in a window of size totalOnes
            if (r - l == totalOnes) {
                maxOnes = max(maxOnes, currentOnes);
            }
        }
        // The minimum swaps needed is the size of the window minus the maximum number of 1's found
        return totalOnes - maxOnes;
    }
};
