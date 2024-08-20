class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        unordered_set<char> st(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (st.find((char) toupper(s[i])) == st.end() || st.find((char) tolower(s[i])) == st.end()) {
                // If one of the cases is missing, split the string into two parts excluding the current character.
                string s1 = longestNiceSubstring(s.substr(0, i)); // Recursively find in the left part.
                string s2 = longestNiceSubstring(s.substr(i + 1)); // Recursively find in the right part.

                return s1.size() >= s2.size() ? s1 : s2;
            }
        }
        return s;
    }
};
// DRY RUN 
// s = "YazaAay"
// Execution:
// 1. Initial Check:
// The string length is greater than 2, so we proceed.
// We create a set of characters from the string: {'Y', 'a', 'z', 'A', 'y'}.
// 2. First Iteration (i = 0, s[i] = 'Y'):
// Check if both 'Y' and 'y' are in the set.
// 'y' is present, so we continue to the next character.
// 3. Second Iteration (i = 1, s[i] = 'a'):
// Check if both 'a' and 'A' are in the set.
// Both are present, so we continue.
// 4. Third Iteration (i = 2, s[i] = 'z'):
// Check if both 'z' and 'Z' are in the set.
// 'Z' is not present.
// We split the string into two parts: s1 = "Ya" and s2 = "aAay".
// Recursively find the longest nice substring for both parts.
// ### Recursive Call 1: s1 = "Ya"
// The string length is less than 2, so no nice substring can exist. Return "".
// ### Recursive Call 2: s2 = "aAay"
// Create a set of characters: {'a', 'A', 'y'}.
// Iterate through s2.
// #### Iteration (i = 0, s2[i] = 'a'):
// Both 'a' and 'A' are present, continue.
// #### Iteration (i = 1, s2[i] = 'A'):
// Both 'A' and 'a' are present, continue.
// #### Iteration (i = 2, s2[i] = 'a'):
// Both 'a' and 'A' are present, continue.
// #### Iteration (i = 3, s2[i] = 'y'):
// 'Y' is not present.
// Split into s1 = "aAa" and s2 = "".
// ##### Recursive Call 3: s1 = "aAa"
// All characters have their counterparts. Return "aAa".
// ##### Recursive Call 4: s2 = ""
// The string is empty. Return "".
// Compare the results of the two recursive calls: "aAa" and "". Return "aAa".
// 5. Back to the first split:
// Compare the results of the two recursive calls: "" and "aAa". Return "aAa".
