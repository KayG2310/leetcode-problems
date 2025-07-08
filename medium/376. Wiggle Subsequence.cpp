// recursive 
class Solution {
private:
    int f(vector<int>& nums, int index, int prev, int n, int par){
        if(index == n) return 0;
        int len = 0; 
        if(nums[index] - nums[prev] > 0 && par == 1){
            len = max(len, 1 + f(nums, index + 1, index, n, !par));
        }
        else if(nums[index] - nums[prev] < 0 && par == 0){
            len = max(len, 1 + f(nums, index + 1, index, n, !par));
        }
        // skip current element
        len = max(len, f(nums, index + 1, prev, n, par));
        return len;
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        return max(f(nums, 1, 0, n, 0), f(nums, 1, 0, n, 1)) + 1;
    }
};

// memoized 
class Solution {
private:
    int f(vector<int>& nums, int index, int prev, int n, int par, vector<vector<vector<int>>>&dp){
        if(index == n) return 0;
        if(dp[index][prev][par] != -1) return dp[index][prev][par];
        int len = 0; 
        if(nums[index] - nums[prev] > 0 && par == 1){
            len = max(len, 1 + f(nums, index + 1, index, n, !par, dp));
        }
        else if(nums[index] - nums[prev] < 0 && par == 0){
            len = max(len, 1 + f(nums, index + 1, index, n, !par, dp));
        }
        // skip current element
        len = max(len, f(nums, index + 1, prev, n, par, dp));
        return dp[index][prev][par] = len;
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return max(f(nums, 1, 0, n, 0, dp), f(nums, 1, 0, n, 1, dp)) + 1;
    }
};

// tabulation 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
        for(int index = n-1; index>=0; index--){
            for(int prev = 0; prev<index; prev++){
                for(int par = 0; par<2; par++){
                    int len = 0; 
                    if(nums[index] - nums[prev] > 0 && par == 1){
                        len = max(len, 1 + dp[index + 1][index][!par]);
                    }
                    else if(nums[index] - nums[prev] < 0 && par == 0){
                        len = max(len, 1 + dp[index + 1][index][!par]);
                    }
                    // skip current element
                    len = max(len, dp[index + 1][prev][par]);
                    dp[index][prev][par] = len;
                }
            }
        }
        return max(dp[1][0][0], dp[1][0][1]) + 1;
    }
};
