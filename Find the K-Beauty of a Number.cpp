class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int i = 0, j = 0, n = str.size();
        int ans = 0;
        while(j < n){
            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                string s = str.substr(i,k);
                int n = stoi(s);
                if(n != 0 && num % n == 0 ){
                    ans++;
                }
                ++i;
                ++j;
            }
                
        }
        
        return ans;
    }
};

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
