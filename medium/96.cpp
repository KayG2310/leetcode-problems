class Solution {
private:
    int f(int x, vector<int>& dp){
        if(x==0 || x==1) return 1; 
        if(dp[x] != -1) return dp[x];
        int sum = 0;
        for(int i=0; i<x; i++){
            int z = i;
            int y = x-z-1;
            sum += f(z, dp)*f(y, dp);
        }
        return dp[x] = sum;
    }
public:
    int numTrees(int n) {
        // if(n==1) return 1;
        vector<int>dp(n+1, -1);
        return f(n, dp);

    }
}; 

// tabulation
class Solution {
public:
    int numTrees(int n) {
        if(n==1) return 1;
        vector<int>dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int x=2; x<=n; x++){
            int sum = 0;
            for(int i=0; i<x; i++){
                int z = i;
                int y = x-z-1;
                sum += dp[z]*dp[y];
            }
        dp[x] = sum;
        }
        return dp[n];

    }
};
