class Solution {
public:
    //we can solve this problem by using sliding window technique
    int countGoodSubstrings(string s) {
        int k=3,i=0,j=0; //k is the size of window
        int count=0,n = s.length();
        map<char,int>mp; //we create map to store the frequency of each character 
        while(j<n){
            mp[s[j]]++; //push the element into map
            if(j-i+1 < k){ //since we want length of substring three so till that point we will just add character
                j++;
            }else{
                if(mp.size() == 3){ //we check that all three entries are unique or not..
                    count++;
                }
              
                mp[s[i]]--; //this is the step where we slide our window
                if(mp[s[i]] == 0){ //if at any step our frquency of that character becomes zero then we have to remove it from our map
                    mp.erase(s[i]);
                }
                i++;
                j++; //to slide our window we move our both pointers
            }
        }
        return count;
    }
};

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0; // If the string is less than length 3, no such substrings exist.

        int count = 0;
        int l = 0; // Left pointer of the sliding window
        int r = 0; // Right pointer of the sliding window

        // Initialize the right pointer to create the first window of size 3
        while (r < s.size()) {
            // Expand the window until it has exactly 3 characters
            if (r - l + 1 < 3) {
                r++;
            } else if (r - l + 1 == 3) {
                // Check if all characters in the current window are unique
                if (s[l] != s[l+1] && s[l] != s[r] && s[l+1] != s[r]) {
                    count++;
                }
                // Move the left pointer to slide the window
                l++;
                // Move the right pointer to expand the window for the next cycle
                r++;
            }
        }
        return count;
    }
};


