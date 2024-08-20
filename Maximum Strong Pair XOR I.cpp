#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumStrongPairXor(vector<int>& v) {
        int l = 0; // Left pointer of the window
        int r = 0; // Right pointer of the window
        int n = v.size();
        int maxi = 0;
        std::sort(v.begin(), v.end()); // Sort the array to help with the strong pair condition

        while (r < n) {
            // Adjust the left pointer to maintain the strong pair condition
            while (l <= r && v[r] - v[l] > v[l]) {
                l++;
            }
            // Check all pairs (v[k], v[r]) where k ranges from l to r-1
            for (int k = l; k < r; k++) {
                maxi = std::max(maxi, v[k] ^ v[r]);
            }
            r++; // Expand the window by moving the right pointer
        }
        return maxi;
    }
};
