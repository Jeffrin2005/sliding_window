#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        map<int, int> mp; 
        long long sum = 0;
        long long ans = 0;
        int i = 0;
        int n = v.size(); 
        for(int j = 0; j < n; j++) {
            mp[v[j]]++; 
            sum+=v[j]; 
            // When window size exceeds k, slide the window
            if(j - i + 1 > k) {
                mp[v[i]]--;
                if(mp[v[i]] == 0){
                    mp.erase(v[i]); 
                }
                sum-=v[i]; 
                i++;
            }
            // Check for window of size exactly k
            if(j - i + 1 == k){
                if(mp.size() == k){
                    ans = max(ans, sum);
                }
            }
        }
        
        return ans;
    }
};
