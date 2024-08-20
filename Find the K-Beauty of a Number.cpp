class Solution {
public:
    int divisorSubstrings(int num, int k) {
         std::string numStr = std::to_string(num);
    int count = 0;
    for (int i = 0; i <= numStr.size() - k; ++i) {
        std::string subStr = numStr.substr(i, k);
        int subNum = std::stoi(subStr);
        if (subNum != 0 && num % subNum == 0) {
            count++;
        }
    }
    return count;
    }
};
