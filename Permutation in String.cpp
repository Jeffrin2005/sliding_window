
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Count(26, 0);
        vector<int>s2Count(26, 0);
        // Initialize the frequency array for s1 and the first window in s2
        for (int i = 0; i < s1.size(); i++){
            ++s1Count[s1[i] - 'a'];
            ++s2Count[s2[i] - 'a'];
        }
        if(s1Count == s2Count) return true;
        // Slide the window over s2
        int i = s1.size();
        while(i < s2.size()){
        ++s2Count[s2[i] - 'a'];  // Include new character in window
        --s2Count[s2[i - s1.size()] - 'a'];  // Remove old character from window
        // Check if current window matches the frequency of s1
        if (s1Count == s2Count) return true;
          i++;
}

        return false;
    }
};
