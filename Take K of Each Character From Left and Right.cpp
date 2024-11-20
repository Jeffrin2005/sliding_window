
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        map<int,int>count;
        for(auto&x :  s) count[x-'a']++;
        if(count[0] < k || count[1] < k || count[2] < k) return -1;
        int minMinutes = INT_MAX;
        int l = 0; 
        for(int r = 0; r < n; r++) {
            // Decrement the count as if we're taking this character from the right end
            count[s[r] - 'a']--;
            while(l <= r && (count[0] < k || count[1] < k || count[2] < k)){
                // Increment the count back as if we're not excluding this character from the left end

//                     The expression (count[0] < k || count[1] < k || count[2] < k) is a critical check to ensure that the current window [l, r] can potentially yield at least k occurrences of each character when taking characters from both ends.
// If any character's count is below k, the algorithm must adjust the window to try and find a valid configuration that meets the requirements.
                count[s[l] - 'a']++;
                l++;
            }
            minMinutes = min(minMinutes, n - (r - l + 1));
        }
        
        return minMinutes;
    }
};
