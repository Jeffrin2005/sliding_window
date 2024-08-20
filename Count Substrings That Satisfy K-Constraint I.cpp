class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
          int l = 0;
          int r = 0;
    int one = 0;
    int  zero = 0;
    int ans = 0;
    while(r < s.size()){
        if (s[r] == '0') zero++;
        else one++;
        // Adjust the window until the condition is met
        while(zero > k && one > k){
            if(s[l] == '0') zero--;
            else one--;
            l++;
        }
        // All substrings ending at r and starting from any index between l and r are valid
        ans+=(r - l + 1);
        r++;
    }

    return ans;
    }
};
