
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int left = 0;
      deque<int>maxDeque, minDeque;
        for (int right = 0; right < n;right++){
            // Maintain maxDeque for the maximum in the current window
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain minDeque for the minimum in the current window
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink the window from the left if the condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }
};
