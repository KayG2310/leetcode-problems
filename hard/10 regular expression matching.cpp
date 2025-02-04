// recusrive +memoized 
class Solution {
private:
    bool f(int i, int j, string &s, string &p, int n, int m, vector<vector<int>>&dp){
        if(i<=0 && j<=0) return true;
        if (j <= 0) return false;
        if (i == 0) {
            if (p[j - 1] == '*') return f(i, j - 2, s, p, n, m, dp);  
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(j>1 && p[j-1] == '*'){
            // we can skip it or take it 
            bool skip = f(i, j-2, s, p, n, m, dp);
            bool pick = i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && f(i-1, j, s,p, n,m, dp);
            return dp[i][j] = skip || pick;
        }
        bool single = i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && f(i-1, j-1, s, p, n, m, dp);
        return dp[i][j] = single;

    }
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        if(m==0) return n==0;
        return f(n, m, s, p, n, m, dp);
    }
}; 


// tabulation 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};
