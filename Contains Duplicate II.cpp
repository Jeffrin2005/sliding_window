class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         map<int, int> map; // This will store the elements and their indices
        int l = 0; // Left pointer
        for (int r = 0; r < nums.size(); r++) {
            if (r - l > k){
                // If the window size exceeds k, move the left pointer
                map.erase(nums[l]);
                l++;
            }
            // Check if the current element is already in the map within the valid range
            if (map.find(nums[r]) != map.end()){
                return true;
            }
            // Add the current element to the map
            map[nums[r]] = r;
        }
        return false;
    }
};
