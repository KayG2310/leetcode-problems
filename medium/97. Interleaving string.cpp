// recursive code --> gave TLE 
class Solution {
private:
private:
    bool f(int n1, int n2, int n3, string& s1, string& s2, string& s3, int i, int j){
        if(j==n1){
            // compare if unvisited sheet adds upto s2 
            int in = 0, inn = 0;
            while(in<n2 && inn<n3){
                while(inn<n3 && s3[inn] == '*') inn++;
                if(inn<n3 && s2[in]==s3[inn]){
                    in++; 
                    inn++;
                }
                else{
                    return false;
                }
            }
            return true;
        }
        if(i==n3) return false; 
        // now comes the big twist 
        bool ans = false;
        if(s1[j]== s3[i]){
            // option1 : pick 
            char temp = s3[i];
            s3[i] = '*';
            ans = ans | f(n1, n2, n3, s1, s2, s3, i+1, j+1);
            s3[i] = temp;
            if(ans) return true;
        }
        ans = ans | f(n1, n2, n3, s1, s2, s3, i+1, j);
        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return false;
        return f(n1, n2, n3,  s1, s2, s3, 0, 0);
    }
};


// trying to optimise 
class Solution {
private:
private:
    int f(int n1, int n2, int n3, string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>&dp){
        if(i==n1 && j==n2) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        if(i<n1 && i+j<n3 && s1[i]==s3[i+j]){
            a = a | f(n1, n2, n3, s1, s2, s3, i+1, j, dp);
        }
        if(j<n2 && i+j<n3 && s2[j]==s3[i+j]){
            a = a | f(n1, n2, n3, s1, s2, s3, i, j+1, dp);
        }
        return dp[i][j] = a;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return false;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return f(n1, n2, n3,  s1, s2, s3, 0, 0, dp)==0? false : true;
    }
}; 
// tabulation 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return false;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        dp[n1][n2] = 1;
        for(int j = n2 - 1; j >= 0; j--) {
            dp[n1][j] = (s2[j] == s3[n1 + j]) && dp[n1][j + 1];
        }
        for(int i = n1 - 1; i >= 0; i--) {
            dp[i][n2] = (s1[i] == s3[i + n2]) && dp[i + 1][n2];
        }
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(s1[i]==s3[i+j]){
                    dp[i][j] = dp[i][j] | dp[i+1][j];
                }
                if(s2[j]==s3[i+j]) dp[i][j] = dp[i][j] | dp[i][j+1];
            }
        }
        return dp[0][0]==0? false : true;
    }
};
