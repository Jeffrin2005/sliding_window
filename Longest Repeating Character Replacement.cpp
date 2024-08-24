#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int characterReplacement(string s, int k) {
        // time comp = o(n), space comp = o(1)
        ll l =0;
        ll r= 0;
        ll max_repeat =0;
        ll ans =0;
        map<ll,ll>mp;
        while(r < s.size()){
            mp[s[r]]++;
            max_repeat = max(max_repeat,mp[s[r]]);
            ll curr_size = (r - l ) + 1;
            if(curr_size - max_repeat <= k){
                ans = curr_size;
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
        
    }
};
