#include <vector>
#include <unordered_map>
// slding window 
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        int totalDistinct = freqMap.size();
        freqMap.clear();

        int count = 0;
        int left = 0, right = 0;
        while (left < n && right < n) {
            freqMap[nums[right]]++;
            while (left <= right && freqMap.size() == totalDistinct) {
                count += n - right;
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
            right++;
        }
        return count;
    }
};
// bruteforce 
class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        int n = v.size();
        map<int, int> countMap;
        for (auto i : v)
            countMap[i]++;
        int distinctCount = countMap.size();
        
        int completeSubarrays = 0;
        for (int i = 0; i < n; i++) {
            map<int, int> m;
            for (int j = i; j < n; j++) {
                m[v[j]]++;
                if (m.size() == distinctCount) {
                    completeSubarrays += n - j;
                    break;
                }
            }
        }
        return completeSubarrays;
    }
};

set
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums){
        unordered_set<int> freq(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> subFreq;
            for (int j = i; j < nums.size(); j++) {
                subFreq.insert(nums[j]);
                if (subFreq.size() == freq.size()) {
                    count++;
                }
            }
        }

        return count;
    }
};
