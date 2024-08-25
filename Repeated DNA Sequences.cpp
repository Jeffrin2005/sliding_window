

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> sequenceCount;
        vector<string> result;

        // We only start checking if the length is at least 10
        if (s.length() < 10) return result;

        // Sliding window to check each 10-letter sequence
        for (int i = 0; i <= s.length() - 10; ++i) {
            string sequence = s.substr(i, 10);
            sequenceCount[sequence]++;
        }

        // Collect sequences that appear more than once
        for (auto& pair : sequenceCount) {
            if (pair.second > 1) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
