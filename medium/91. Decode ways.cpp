class Solution {
private:
    int f(int index, string &s, vector<int> &dp){
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) return dp[index];

        int ways = f(index + 1, s, dp);  // single character

        if (index + 1 < s.size()) {
            int num = stoi(s.substr(index, 2));
            if (num >= 10 && num <= 26) {
                ways += f(index + 2, s, dp);  // two character
            }
        }

        return dp[index] = ways;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};
