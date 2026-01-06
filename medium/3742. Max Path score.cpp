// memoization 
class Solution {
private:
    int f(int i, int j, int n, int m, vector<vector<int>>& grid, int k, int curcost, vector<vector<vector<int>>>&dp){
        if(curcost>k) return INT_MIN; 
        if(i==n-1 && j==m-1){
            if(grid[i][j]==0 || curcost+1 <=k) return grid[i][j];
            else return INT_MIN;
        }
        if(dp[i][j][curcost] != -1) return dp[i][j][curcost];
        int score = INT_MIN; 
        if(j+1<m) {
            if(grid[i][j]==0) score = max(score, f(i, j+1, n, m, grid, k, curcost, dp));
            else if(grid[i][j]==1) score = max(score, 1+f(i, j+1, n, m, grid, k, curcost+1, dp));
            else score = max(score, 2+f(i, j+1, n, m, grid, k, curcost+1, dp));
        }
        if(i+1<n){
            if(grid[i][j]==0) score = max(score, f(i+1, j, n, m, grid, k, curcost, dp));
            else if(grid[i][j]==1) score = max(score, 1+f(i+1, j, n, m, grid, k, curcost+1, dp));
            else score = max(score, 2+f(i+1, j, n, m, grid, k, curcost+1, dp));
        }
        return dp[i][j][curcost] = score;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        int ans = f(0,0, n, m, grid, k, 0, dp);
        if(ans<0) return -1;
        return ans;
    }
}; 

// tabulation 
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k+1, INT_MIN)));
        for(int curcost = 0; curcost <= k; curcost++) {
            if(grid[n-1][m-1] == 0) dp[n-1][m-1][curcost] = 0;
            else if(grid[n-1][m-1] == 1 && curcost + 1 <= k) dp[n-1][m-1][curcost] = 1;
            else if(grid[n-1][m-1] == 2 && curcost + 1 <= k) dp[n-1][m-1][curcost] = 2;
            else dp[n-1][m-1][curcost] = INT_MIN;
        }

        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1) continue;
                for(int curcost = k; curcost >=0; curcost--){
                    int score = INT_MIN; 
                    if(j+1<m) {
                        if(grid[i][j]==0) score = max(score, dp[i][j+1][curcost]);
                        else if(grid[i][j]==1 && curcost+1<=k) score = max(score, 1+dp[i][j+1][curcost+1]);
                        else if(grid[i][j]==2 && curcost+1<=k) score = max(score, 2+dp[i][j+1][curcost+1]);
                    }
                    if(i+1<n){
                        if(grid[i][j]==0) score = max(score, dp[i+1][j][curcost]);
                        else if(grid[i][j]==1 && curcost+1<=k) score = max(score, 1+dp[i+1][j][curcost+1]);
                        else if(grid[i][j]==2 && curcost+1<=k) score = max(score, 2+dp[i+1][j][curcost+1]);
                    }
                    dp[i][j][curcost] = score;
                }
            }
        }
        int ans = dp[0][0][0];
        if(ans<0) return -1;
        return ans;
    }
}; 

// space optimisation 
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>cur(m, vector<int>(k+1, INT_MIN)), next(m, vector<int>(k+1, INT_MIN));
        for(int curcost = 0; curcost <= k; curcost++) {
            if(grid[n-1][m-1] == 0) cur[m-1][curcost] = 0;
            else if(grid[n-1][m-1] == 1 && curcost + 1 <= k) cur[m-1][curcost] = 1;
            else if(grid[n-1][m-1] == 2 && curcost + 1 <= k) cur[m-1][curcost] = 2;
            else cur[m-1][curcost] = INT_MIN;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1) continue;
                for(int curcost = k; curcost >=0; curcost--){
                    int score = INT_MIN; 
                    if(j+1<m) {
                        if(grid[i][j]==0) score = max(score, cur[j+1][curcost]);
                        else if(grid[i][j]==1 && curcost+1<=k) score = max(score, 1+cur[j+1][curcost+1]);
                        else if(grid[i][j]==2 && curcost+1<=k) score = max(score, 2+cur[j+1][curcost+1]);
                    }
                    if(i+1<n){
                        if(grid[i][j]==0) score = max(score, next[j][curcost]);
                        else if(grid[i][j]==1 && curcost+1<=k) score = max(score, 1+next[j][curcost+1]);
                        else if(grid[i][j]==2 && curcost+1<=k) score = max(score, 2+next[j][curcost+1]);
                    }
                    cur[j][curcost] = score;
                }
            }
            next = cur;
        }
        int ans = cur[0][0];
        if(ans<0) return -1;
        return ans;
    }
};
