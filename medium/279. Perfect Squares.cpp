// recursive code 
class Solution {
private:
    int f(int n){
        if(n==0) return 0;
        int steps = 1e9;
        for(int i=1; i*i<=n; i++){
            if(n-i*i>=0) steps = min(steps, 1+f(n-i*i));
            else break;
        }
        return steps;
    }
public:
    int numSquares(int n) {
        return f(n);
    }
};

// memoized
class Solution {
private:
    int f(int n, vector<int>&dp){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int steps = 1e9;
        for(int i=1; i*i<=n; i++){
            if(n-i*i>=0) steps = min(steps, 1+f(n-i*i, dp));
            else break;
        }
        return dp[n] = steps;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return f(n, dp);
    }
};
