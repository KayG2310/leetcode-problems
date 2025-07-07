// tle
class Solution {
private:
    int f(int n, int m, vector<int>& ar, vector<int>& arr, int i, int j){
        if(i==n || j==m) return 0;
        int len = 0; 
        if(ar[i]==arr[j]){
            len = max(len, 1+f(n,m,ar,arr, i+1, j+1));
        }
        return len;
    }
public:
    int findLength(vector<int>& ar, vector<int>& arr) {
        int n = ar.size();
        int m = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, f(n, m, ar, arr, i, j));
            }
        }
        return ans;
    }
};

// tabulation 
class Solution {
private:
    int f(int n, int m, vector<int>& ar, vector<int>& arr, int i, int j){
        if(i==n || j==m) return 0;
        int len = 0; 
        if(ar[i]==arr[j]){
            len = max(len, 1+f(n,m,ar,arr, i+1, j+1));
        }
        return len;
    }
public:
    int findLength(vector<int>& ar, vector<int>& arr) {
        int n = ar.size();
        int m = arr.size();
        int ans = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int len = 0; 
                if(ar[i]==arr[j]){
                    len = max(len, 1+dp[i+1][j+1]);
                }
                dp[i][j] = len;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// space optimised
class Solution {
private:
    int f(int n, int m, vector<int>& ar, vector<int>& arr, int i, int j){
        if(i==n || j==m) return 0;
        int len = 0; 
        if(ar[i]==arr[j]){
            len = max(len, 1+f(n,m,ar,arr, i+1, j+1));
        }
        return len;
    }
public:
    int findLength(vector<int>& ar, vector<int>& arr) {
        int n = ar.size();
        int m = arr.size();
        int ans = 0;
        vector<int>cur(m+1, 0), ahead(m+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int len = 0; 
                if(ar[i]==arr[j]){
                    len = max(len, 1+ahead[j+1]);
                }
                cur[j] = len;
                ans = max(ans, cur[j]);
            }
            ahead = cur; 
        }
        return ans;
    }
};
