
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 1;
        sort(nums.begin(), nums.end());
        
        while (r < nums.size()) {
            if (nums[r] - nums[l] == 1) {
                res = max(res, r - l + 1);
            }
            while(nums[r] - nums[l] > 1) {
                l++; // Increment left pointer
            }
            r++; // Increment right pointer
        }
        return res;
    }
};
