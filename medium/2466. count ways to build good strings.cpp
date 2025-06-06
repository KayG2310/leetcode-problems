// brute force tc = exponential 
const int mod = 1e9+7;
class Solution {
private:
    int f(int len, int zero, int one, int mid){
        if(mid==len){
            return 1;
        }
        if(len>mid) return 0;
        long long cnt = 0;
        cnt = (cnt+f(len+zero, zero, one, mid))%mod;
        cnt = (cnt+f(len+one, zero, one, mid))%mod;
        return cnt%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        for(int i=low; i<=high; i++){
            ans = (ans+f(0, zero, one, i)%mod)%mod;
        }
        return ans;
    }
}; 
// better -- avoid the traversal from high to low 
const int mod = 1e9+7;
class Solution {
private:
    int f(int len, int zero, int one, int low, int high){
        if(len>high) return 0;
        int cnt = 0;
        if(len>=low) cnt = 1;
        cnt = (cnt+f(len+zero, zero, one, low, high))%mod;
        cnt = (cnt+f(len+one, zero, one, low, high))%mod;
        return cnt%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // int cnt = 0;
        return f(0, zero, one, low, high)%mod;
    }
};

// optimal 
const int mod = 1e9+7;
class Solution {
private:
    int f(int len, int zero, int one, int low, int high, vector<int>&dp){
        if(len>high) return 0;
        if(dp[len] != -1) return dp[len];
        int cnt = 0;
        if(len>=low) cnt = 1;
        cnt = (cnt+f(len+zero, zero, one, low, high, dp))%mod;
        cnt = (cnt+f(len+one, zero, one, low, high, dp))%mod;
        return dp[len] = cnt%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // int cnt = 0;
        vector<int>dp(high+1, -1);
        return f(0, zero, one, low, high, dp)%mod;
    }
};
