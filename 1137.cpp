// recursive 
class Solution {
private: 
    int f(int n){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        return f(n-3)+f(n-2)+f(n-1);
    }
public:
    int tribonacci(int n) {
        return f(n);
    }
};

// memoized 
class Solution {
private: 
    int f(int n, vector<int>&dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-3, dp)+f(n-2, dp)+f(n-1, dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1, -1);
        return f(n, dp);
    }
};
// tabulation 
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        // if(n==2) 
        vector<int>dp(n+1, 0);
        dp[1] = dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};
