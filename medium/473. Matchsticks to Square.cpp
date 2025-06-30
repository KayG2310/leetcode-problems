// recursive code 
class Solution {
private: 
    bool f(vector<int>& m, int n, int s1, int s2, int s3, int s4, int index, map<vector<int>, bool>&dp, int sum){
        if(index == n){
            return (s1==s2 && s2==s3 && s3 == s4);
        }
        // if(dp[{index, s1, s2, s3, s4}] != -1) return dp[{index, s1, s2, s3, s4}];
        int ans = false; 
        if(s1+m[index]<=sum/4) ans = ans | f(m, n, s1+m[index], s2, s3, s4, index+1, dp, sum);
        if(ans) return true; 
        if(s2+m[index]<=sum/4) ans = ans | f(m, n, s1, s2+m[index], s3, s4, index+1, dp, sum);
        if(ans) return true; 
        if(s3+m[index]<=sum/4)ans = ans | f(m, n, s1, s2, s3+m[index], s4, index+1, dp, sum);
        if(ans) return true; 
        if(s4+m[index]<=sum/4)ans = ans | f(m, n, s1, s2, s3, s4+m[index], index+1, dp, sum);
        return ans; 
    }
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        if(n<4) return false;
        int sum = accumulate(m.begin(), m.end(), 0);
        if(sum%4) return false;
        int s1=0, s2=0, s3=0, s4=0; 
        map<vector<int>, bool>dp;
        return f(m, n, s1, s2, s3, s4, 0, dp, sum);
    }
};

// improved recursive 
class Solution {
private: 
    bool f(vector<int>& m, int n, int s1, int s2, int s3, int s4, int index, int sum){
        if(index == n){
            return (s1==s2 && s2==s3 && s3 == s4);
        }
        // if(dp[{index, s1, s2, s3, s4}] != -1) return dp[{index, s1, s2, s3, s4}];
        int ans = false; 
        if(s1+m[index]<=sum/4) ans = ans | f(m, n, s1+m[index], s2, s3, s4, index+1, sum);
        if(ans) return true; 
        if(s2+m[index]<=sum/4) ans = ans | f(m, n, s1, s2+m[index], s3, s4, index+1, sum);
        if(ans) return true; 
        if(s3+m[index]<=sum/4)ans = ans | f(m, n, s1, s2, s3+m[index], s4, index+1, sum);
        if(ans) return true; 
        if(s4+m[index]<=sum/4)ans = ans | f(m, n, s1, s2, s3, s4+m[index], index+1, sum);
        return ans; 
    }
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        if(n<4) return false;
        int sum = accumulate(m.begin(), m.end(), 0);
        if(sum%4) return false;
        int s1=0, s2=0, s3=0, s4=0; 
        sort(m.rbegin(), m.rend());
        return f(m, n, s1, s2, s3, s4, 0, sum);
    }
};
