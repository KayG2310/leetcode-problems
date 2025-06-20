class Solution {
private:
    double max(double a, double b){
        if(a>=b) return a;
        return b;
    }
    double f(vector<int>&nums, int n, int index, int last, int k, vector<vector<vector<double>>>&dp){
        if(index == n) {
            double sum = 0.0;
            for(int i=last; i<n; i++){
                sum += (double)(nums[i]);
            }
            return sum/(double)(n-last);
        }
        if(k == 1) {
            double sum = 0.0;
            for(int i=last; i<n; i++){
                sum += (double)(nums[i]);
            }
            return sum/(double)(n-last);
        }
        // choice 1 : continue current chioice 2: discontinue
        if(dp[index][last][k] != -1) return dp[index][last][k];
        double sum = 0.0;
        for(int i=last; i<=index; i++){
            sum += (double)nums[i];
        }
        return dp[index][last][k] = max(f(nums, n, index+1, last, k, dp), sum/((double)(index-last+1))+f(nums, n, index+1, index+1, k-1, dp));
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1.0)));
        return f(nums, n, 0, 0, k, dp);
    }
};
/*
f(0, 0, k)
f(1, 0, k) 
*/
