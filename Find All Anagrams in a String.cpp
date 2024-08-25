
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        // Frequency maps for p and the current window in s
        vector<int> pCount(26, 0), sCount(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (pCount == sCount) result.push_back(0);

        // Sliding window to check the rest of s
        for (int i = p.size(); i < s.size(); ++i) {
            sCount[s[i] - 'a']++;  // Include new character in window
            sCount[s[i - p.size()] - 'a']--;  // Remove old character from window

            if (sCount == pCount) {
                result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }
};
