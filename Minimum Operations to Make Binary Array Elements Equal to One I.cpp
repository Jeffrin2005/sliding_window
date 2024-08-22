class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                int j = i;
                while (j < i + 3) {
                    nums[j] ^= 1; // Flip the bit using XOR
                    j++;
                }
                operations++;
            }
        }

        for (int num : nums) {
            if (num == 0) {
                return -1;
            }
        }
        return operations;
    }
};