class Solution {
public:
    int maximumLengthSubstring(string s) {
         map<char, int> mp;
    int l = 0;
    int maxLen = 0;
    int r = 0;
    while(r < s.size()){
        mp[s[r]]++;
        // If a character count exceeds 2, shrink the window from the left
        while(mp[s[r]] > 2){
            mp[s[l]]--;
            l++;
        }
        // Update the maximum length found
        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
    }
};
