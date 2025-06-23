class Solution {
public:
    vector<int> findCoins(vector<int>& dp) {
        int n = dp.size();
        dp.insert(dp.begin(), 1); // prepend dp[0] = 1
        vector<int> res;
        for (int a = 1; a <= n; ++a) {
            if (dp[a] > 1) return {};
            if (dp[a] == 0) continue;
            res.push_back(a);
            for (int v = n; v >= a; --v) {
                dp[v] -= dp[v - a];
                if (dp[v] < 0) return {};
            }
        }
        return res;
    }
};
