class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<string, int> hashmap;
        int n = s.size();
        int ans = 0;
        int size = n-minSize;
            for (int i = 0; i <= size; i++) {
            std::string substring = s.substr(i, minSize);
            if (hashmap.find(substring) == hashmap.end()) {
                hashmap[substring] = 1; // Initialize if not present
            } else {
                hashmap[substring]++; // Increment the count
            }
        }
        for (auto &str:hashmap) {
            set<char> subs(begin(str.first),end(str.first));
            if (subs.size() <= maxLetters) {
                ans = max(ans, str.second);
            }
        }
        return ans;
    }
};
