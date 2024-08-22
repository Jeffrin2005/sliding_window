class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(); // Total number of minutes the store is open
        int baseSatisfied = 0, maxGain = 0, currentGain = 0; // Initialize counters for satisfied customers and potential gains

        // Calculate base satisfied customers and initial window gain
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i]; // Add to base satisfied if the owner is not grumpy
            }
            if (i < minutes && grumpy[i] == 1) {
                currentGain += customers[i]; // Calculate potential gain in the first 'minutes' window if the owner is grumpy
            }
        }
        maxGain = currentGain; // Set initial max gain as the gain from the first window

        // Sliding window to find the maximum gain
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentGain += customers[i]; // Add to current gain if the owner is grumpy at minute i
            }
            if (grumpy[i - minutes] == 1) {
                currentGain -= customers[i - minutes]; // Subtract from current gain if the owner was grumpy at the start of the previous window
            }
            maxGain = max(maxGain, currentGain); // Update max gain if the current window gain is higher
        }

        return baseSatisfied + maxGain; // Return total satisfied customers including base and additional gain from using the technique
    }
};
