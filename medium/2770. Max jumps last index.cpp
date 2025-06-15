// recursive code 
class Solution {
private:
    int f(int index, vector<int>&nums, int target, int n){
        if(index == n) return 0; 
        if(index == n-1) return 0;
        int steps = INT_MIN;
        for(int i=index+1; i<n; i++){
            if(abs(nums[i]-nums[index])<=target){
                steps = max(steps, 1+f(i, nums, target, n));
            }
        }
        return steps==INT_MIN || steps==0 ? -1: steps;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return 0;
        return f(0, nums, target, n);
    }
};

// memoized 
class Solution {
private:
    int f(int index, vector<int>&nums, int target, int n, vector<int>&dp){
        if(index == n) return 0; 
        if(index == n-1) return 0;
        if(dp[index] != -2) return dp[index];
        int steps = INT_MIN;
        for(int i=index+1; i<n; i++){
            if(abs(nums[i]-nums[index])<=target){
                steps = max(steps, 1+f(i, nums, target, n, dp));
            }
        }
        return dp[index] = steps==INT_MIN || steps==0 ? -1: steps;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int>dp(n+1, -2);
        return f(0, nums, target, n, dp);
    }
}; 

// tabulation 
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int>dp(n+1, 0);
        for(int index = n-2; index>=0; index--){
            int steps = INT_MIN;
            for(int i=index+1; i<n; i++){
                if(abs(nums[i]-nums[index])<=target){
                    steps = max(steps, 1+dp[i]);
                }
            }
            dp[index] = steps==INT_MIN || steps==0 ? -1: steps;
        }
        return dp[0];
    }
};
