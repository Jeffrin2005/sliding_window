
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int result = 0;

        // Try for every possible number of unique characters
        for (int numUniqueTarget = 1; numUniqueTarget <= 26; numUniqueTarget++) {
            int l = 0, r = 0;
            vector<int> count(128, 0);
            int numUnique = 0, numNoLessThanK = 0;

            while (r < n) {
                // Expand the window by including s[r]
                if (count[s[r]] == 0) numUnique++;
                count[s[r]]++;
                if (count[s[r]] == k) numNoLessThanK++;
                r++;

                // Shrink the window until we have exactly numUniqueTarget unique characters
                while (numUnique > numUniqueTarget) {
                    if (count[s[l]] == k) numNoLessThanK--;
                    count[s[l]]--;
                    if (count[s[l]] == 0) numUnique--;
                    l++;
                }

                // Check if this window is valid
                if (numUnique == numUniqueTarget && numUnique == numNoLessThanK) {
                    result = max(result, r - l);
                }
            }
        }

        return result;
    }
};
