class Solution {
public:
    void f(int i, string &ans, string &s, unordered_map<string, bool> &dp, vector<string>&res) {
        if (i >= s.size()) {
            res.push_back(ans);
            return;
        }
        for (int j = i + 1; j <= i + 10  &&  j <= s.size(); j++) {
            string word = s.substr(i, j - i); // j-i is length of substr 
            if (dp.find(word) != dp.end()) {
                if (ans.size() == 0) ans = word;
                else ans += " " + word;
                f(j, ans, s, dp, res);
                int x = 0;
                while (x < word.size()) {
                    x++;
                    ans.pop_back();
                    // removing the word
                }
                if (ans.size() > 0) ans.pop_back(); // extra space
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string ans = "";
        unordered_map<string, bool> dp;
        for (auto x: wordDict) {
            dp[x] = true;
        }
        f(0, ans, s, dp, res);
        return res;
    }
};
