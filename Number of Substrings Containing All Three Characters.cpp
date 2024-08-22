

class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> count; // Using map to count occurrences of 'a', 'b', and 'c'
        int l = 0, result = 0;
        
        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++;
            
            while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
                result += s.size() - r;
                count[s[l]]--;
                l++;
            }
        }
        
        return result;
    }
};
