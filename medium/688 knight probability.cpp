class Solution {
private:
    double f(int n, int k, int i, int j, vector<int>&dx, vector<int>&dy, vector<vector<vector<double>>>&dp){
        if(i>=n || i<0 || j>=n || j<0) return 0.0;
        if(k==0) return 1.0;
        if(dp[k][i][j] != -1) return dp[k][i][j];
        double ans = 0;
        for(int ii=0; ii<8; ii++){
            int nr = i+dx[ii];
            int nc = j+dy[ii];
            ans += f(n, k-1, nr, nc, dx, dy, dp);
        }
        return dp[k][i][j] = ans;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<int>dx = {-2, -2, 2, 2, -1, 1, -1, 1};
        vector<int>dy = {1, -1, 1, -1, 2, 2, -2, -2};
        vector<vector<vector<double>>>dp(k+1, vector<vector<double>>(n+1, vector<double>(n+1, 0)));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[0][i][j] = 1.0;
            }
        }

        for(int kk=0; kk<=k; kk++){
            for
        }
        double fav_outcomes = f(n, k, row, column, dx, dy, dp);

        return fav_outcomes/pow(8.0, k);
    }
};
