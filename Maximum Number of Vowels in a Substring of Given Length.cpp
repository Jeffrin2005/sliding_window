class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;  // Use 'l' for the left pointer
        int r = 0;  // Use 'r' for the right pointer

        int ans = 0;  // Initialize the maximum number of vowels to 0
        int temp = 0;  // Initialize a temporary count of vowels in the current window

        // Loop through the string with a sliding window approach
        while(r < n){
            // If the current character is a vowel, increment the temporary count
            if(isVowel(s[r])){
               temp++;
           }
          
           // If the window size is exactly k, slide the window by moving the left pointer
           if(r - l + 1 == k){
               ans = max(ans, temp);  // Update the maximum number of vowels found so far
               if(isVowel(s[l])){
                   temp--;  // Decrement the temporary count if the first character in the window is a vowel
               }
               l++;  // Move the left pointer to shrink the window from the left
           }
           
           r++;  // Move the right pointer to expand the window
        }
        
        return ans; 
    }
};
