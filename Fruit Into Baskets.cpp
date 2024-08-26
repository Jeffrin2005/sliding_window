

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> count;
        int max_fruits = 0;
        int l = 0; 
        for (int r = 0; r < fruits.size(); r++){ 
            // Increase the count of the current fruit
            count[fruits[r]]++;
            // Shrink the window until we have only two types of fruits
            while(count.size() > 2){
                count[fruits[l]]--;
                if(count[fruits[l]] == 0){
                    count.erase(fruits[l]);
                }
                l++; 
            }
            max_fruits = max(max_fruits, r - l + 1);
        }

        return max_fruits;
    }
};
