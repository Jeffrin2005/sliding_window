
class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        set<int> seen;
        int maxScore = 0;
        int currentScore = 0;
        int l = 0;  // Left pointer
        for (int r = 0; r < nums.size(); r++){  // Right pointer
            // Move the left pointer to maintain uniqueness
            while(seen.find(nums[r]) != seen.end()) {
                seen.erase(nums[l]);
                currentScore -= nums[l];
                ++l;
            }
            // Add the current number to the set and update the current score
            seen.insert(nums[r]);
            currentScore += nums[r];
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
