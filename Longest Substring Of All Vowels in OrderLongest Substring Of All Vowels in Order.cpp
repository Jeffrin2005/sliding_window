class Solution {
public:
    int longestBeautifulSubstring(string s) 
    {
        string need = "aeiou";
        int ans = 0, n = s.size();
        int i = 0, j = 0, cur = 0;
        while(j<n)
        {
            if(s[j] == need[cur])
            {
                while(s[j] == need[cur]) j++;
                cur++;
                if(cur == 5) ans = max(ans, j-i);
            }
            else 
            {
                cur = 0;
                while(j < n and s[j] != need[cur]) j++;
                i = j;
            }
        }
        return ans;
    }
};
