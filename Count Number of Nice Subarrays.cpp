class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
          // Transform nums to only 0s and 1s, 1 for odd, 0 for even
    for (int& num : nums) {
        num = num % 2;
    }
    
    // Initialize prefix sum and hash map
    int prefix_sum = 0;
    map<int, int> count_map;
    count_map[0] = 1;  // To handle the case when the prefix sum itself is exactly k
    int result = 0;
    
    // Iterate over the array
    for (int num : nums) {
        prefix_sum += num;
        // Check if there's a prefix sum that, when subtracted from current prefix sum, equals k
        if (count_map.find(prefix_sum - k) != count_map.end()) {
            result += count_map[prefix_sum - k];
        }
        
        // Update the count of this prefix sum in the map
        count_map[prefix_sum]++;
    }
    
    return result;
    }
};
