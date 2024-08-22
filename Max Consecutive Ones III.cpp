class Solution {
public:
    bool check(vector<int>& nums, int length, int k){
        // length =mid; 
        int zeroCount = 0;
        int left = 0;
        // converting length to full of 1's 
        // Sliding window to count zeros in a window of 'length'
        for (int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                zeroCount++;
            }
            if(right - left + 1 > length){
                if(nums[left] == 0){
                    zeroCount--;// remvoing the 0 from out zerocount , no more considered the current zero for out new window
                }
                left++;
            }
            if (right - left + 1 == length && zeroCount <= k){
                return true;
            }
        }
        return false;
    }

    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int  high = nums.size();
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (check(nums, mid, k)) {
                low = mid + 1;// If a subarray of length 'mid' is valid,search for higher mid length 
            } else {
                high = mid - 1;// If not, search for lower mid length
            }
        }
        return high;
    }
};
