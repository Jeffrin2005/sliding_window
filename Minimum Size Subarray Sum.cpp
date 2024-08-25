
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX; 
        int l = 0;
        int sum = 0;
        for(int r = 0; r < n;r++){
            sum += nums[r];
            while (sum >= target){
                minLength = min(minLength, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
