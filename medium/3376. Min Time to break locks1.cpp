class Solution {
public:
    // Recursive function to solve the problem
    int solve(int mask, int x, int K, vector<int>& nums, int n, vector<vector<int>>&dp) {
        // If all tasks are completed, return 0
        if (mask == (1 << n) - 1) {
            return 0;
        }
        if(dp[mask][x] != -1) return dp[mask][x];
        int mini = INT_MAX;
        
        // Explore all tasks
        for (int i = 0; i < n; i++) {
            // If task i is not completed (not in the mask)
            if (!(mask & (1 << i))) {
                // Calculate time required to complete task i
                int time = (nums[i] + x - 1) / x;
                
                // Recursively compute the minimum time for the next task
                mini = min(mini, time + solve(mask | (1 << i), x + K, K, nums, n, dp));
            }
        }

        return dp[mask][x] = mini;
    }

    // Function to find the minimum time to complete all tasks
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();  // Number of tasks
        int x = 1; 
        vector<vector<int>>dp(1<<n, vector<int>(n*K+2, -1));
        return solve(0, x, K, strength, n, dp);  // Start with no tasks completed
    }
};
