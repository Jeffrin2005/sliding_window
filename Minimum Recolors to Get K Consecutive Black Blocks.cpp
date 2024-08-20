class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int l = 0, r = 0;
        int count = 0; 
        int ans = INT_MAX;
        while (r < n){
            // Expand the window by including the current block at 'r'
            if(blocks[r] == 'W'){
                count++;
            }
            r++;
            // When the window size reaches 'k', calculate and then slide the window
            if (r - l == k){
                // Update the minimum number of recolors needed
                ans = min(ans, count);
                // Slide the window: remove the element at 'l' and move 'l' right
                if(blocks[l] == 'W'){
                    count--;
                }
                l++;
            }
        }
        return ans;
    }
};
