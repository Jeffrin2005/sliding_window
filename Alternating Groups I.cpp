#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors) {
          int count = 0;
        int n = colors.size();
        
        // Iterate through the array, considering the circular nature
        for (int i = 0; i < n; i++){
            // Use modulo operation to wrap around
            int next1 = (i + 1) % n;
            int next2 = (i + 2) % n;
            // Check if the current, next1, and next2 form an alternating group
            if (colors[i] == colors[next2] && colors[next1] != colors[i] && colors[next1] != colors[next2]) {
                count++;
            }
        }
        
        return count;
    }
};
