class Solution {
private: 
    int f(vector<pair<int, int>>&arr, int m, int n, int index, int k, vector<vector<vector<int>>>&dp){
        if(index == k) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int size = 0;
        if(arr[index].first<=n && arr[index].second<=m){
            // choice 1 : pick it 
            size = max(size, 1+f(arr, m-arr[index].second, n-arr[index].first, index+1, k, dp));
        }
        // choice 2 : dont pick it
        size = max(size, f(arr, m, n, index+1, k, dp));
        return dp[index][m][n] = size;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size(); 
        vector<pair<int, int>>arr(k);
        for(int i=0; i<k; i++){
            int x = strs[i].length();
            int sum = 0;
            for(char c: strs[i]) {
                sum += (c-'0');
            }
            arr[i].first = sum; // ones
            arr[i].second = x-sum; // zeroes
            
        }
        vector<vector<vector<int>>>dp(k+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(arr, m, n, 0, k, dp);
    }
};
