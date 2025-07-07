// brute force 
class Solution {
private: 
    int f(int low, int high){
        if(low>=high) return 0; 
        int money = 1e9; 
        for(int i=low; i<=high; i++){
            int mon = i; 
            money = min(money, max(mon+f(low, i-1), mon+f(i+1, high)));
        }
        return money;
    }
public:
    int getMoneyAmount(int n) {
        return f(1, n);
    }
};

// memoize
class Solution {
private: 
    int f(int low, int high, vector<vector<int>>&dp){
        if(low>=high) return 0; 
        if(dp[low][high] != -1) return dp[low][high];
        int money = 1e9; 
        for(int i=low; i<=high; i++){
            int mon = i; 
            money = min(money, max(mon+f(low, i-1, dp), mon+f(i+1, high, dp)));
        }
        return dp[low][high] = money;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+3, vector<int>(n+3, -1));
        return f(1, n, dp);
    }
};

// tabulation 
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+3, vector<int>(n+3, 0));
        for(int low = n; low>=1; low--){
            for(int high = low+1; high<=n ; high++){
                int money = 1e9; 
                for(int i=low; i<=high; i++){
                    int mon = i; 
                    money = min(money, max(mon+dp[low][i-1], mon+dp[i+1][high]));
                }
                dp[low][high] = money;                
            }
        }
        return dp[1][n];
    }
};
