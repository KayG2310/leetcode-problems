// #define pii pair<long long, long long>
// approach - 1 BFS 
#define pii pair<long long, long long>
class Solution {
public:
    int integerReplacement(int n) {
        int steps = 0;
        queue<pii>q;
        n = (long long)n;
        q.push({n, 0});

        while(!q.empty()){
            auto it = q.front(); q.pop();
            if(it.first == 1) return it.second;
            if(it.first%2 == 0) q.push({it.first/2, it.second+1});
            else{
                q.push({it.first-1, it.second+1});
                if(it.first <= INT_MAX) q.push({it.first+1, it.second+1});
            }
        }
        return -1;
    }
}; 

// approach 2 - DP
class Solution {
private:
    int f(long long n, map<long long, int>&dp){
        if(n==1) return 0; 
        if(dp.find(n) != dp.end()) return dp[n];
        int steps = INT_MAX; 
        if(n%2==0) steps = min(steps, 1+f(n/2, dp));
        else{
            steps = min(steps, 1+f(n-1, dp));
            if(n<=INT_MAX) steps = min(steps, 1+f(n+1, dp));
        }
        return dp[n] = steps;
    }
public:
    int integerReplacement(int n) {
        map<long long, int>dp;
        return f((long long)n, dp);
    }
};
