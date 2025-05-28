class Solution {
public:// time comp = o(n), space comp = o(1);
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1); 
        int i = 0;
        int j = 0; 

        // iM' not sure it is working fien .oo ddon 
        while (j < n){
            // If the current element is not consecutive to the previous
            if (j > 0 && nums[j] - nums[j - 1] != 1) {
                i = j; // Reset the start of the window
            }
            // Shrink the window from the left if its size exceeds k
            while (i < j && j - i + 1 > k) {
                i++;
            }

            // If the window size is exactly k, set the power
            if (j - i + 1 == k)
                ans[j - k + 1] = nums[j];

            j++; // Expand the window to the right
        }
        return ans;
    }
};      // time comp =o(n), space comp = o(n)
class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        int n=v.size();
        vector<int>temp(n,1);
        vector<int>ans(n-k+1,-1);
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]==1){
                temp[i]=temp[i-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            if(temp[i]>=k){
                ans[i-k+1]=v[i];
            }
        }
        return ans;
    }
};
