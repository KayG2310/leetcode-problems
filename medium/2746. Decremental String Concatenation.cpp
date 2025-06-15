// recursive code
class Solution {
private: 
    int f(int index, vector<string>&words, int len, char start, char end, int n){
        if(index == n) return len;
        int lena = 0;
        // last + cur word 
        int x = words[index].length();
        if(words[index][0] == end){
            lena = f(index+1, words, len+x-1, start, words[index][x-1] ,n);
        }
        else{
            lena = f(index+1, words, len+x, start, words[index][x-1] , n);
        }
        int lenb = 0;
        // cur word + last 
        if(words[index][x-1] == start){
            lenb = f(index+1, words, len+x-1, words[index][0], end, n);
        }
        else lenb = f(index+1, words, len+x, words[index][0], end, n);
        return min(lena, lenb);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        return f(1, words, words[0].length(), words[0][0], words[0][words[0].length()-1], n);
    }
};

// memoized code 
class Solution {
private: 
    int f(int index, vector<string>& words, char start, char end, int n, vector<vector<vector<int>>>& dp) {
        if (index == n) return 0;
        if (dp[index][start - 'a'][end - 'a'] != -1) return dp[index][start - 'a'][end - 'a'];
        int x = words[index].length();
        char cur_start = words[index][0];
        char cur_end = words[index][x - 1];
        int cost1 = (cur_start == end ? x - 1 : x) + f(index + 1, words, start, cur_end, n, dp);
        int cost2 = (cur_end == start ? x - 1 : x) + f(index + 1, words, cur_start, end, n, dp);
        return dp[index][start - 'a'][end - 'a'] = min(cost1, cost2);
    }

public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(26, vector<int>(26, -1)));
        int initial_len = words[0].length();
        return initial_len + f(1, words, words[0][0], words[0].back(), n, dp);
    }
};

// tabulation might be quickest 
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int INF = 1e9;

        // dp[i][start][end] = min length to build using first i words with start & end chars
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26, INF)));

        int first_len = words[0].length();
        int s = words[0][0] - 'a';
        int e = words[0].back() - 'a';
        dp[0][s][e] = first_len;

        for (int i = 1; i < n; ++i) {
            int len = words[i].length();
            int cs = words[i][0] - 'a';
            int ce = words[i].back() - 'a';

            vector<vector<int>> new_dp(26, vector<int>(26, INF));

            for (int start = 0; start < 26; ++start) {
                for (int end = 0; end < 26; ++end) {
                    if (dp[i-1][start][end] == INF) continue;

                    // attach to end
                    int cost1 = (cs == end ? len - 1 : len);
                    new_dp[start][ce] = min(new_dp[start][ce], dp[i-1][start][end] + cost1);

                    // attach to start
                    int cost2 = (ce == start ? len - 1 : len);
                    new_dp[cs][end] = min(new_dp[cs][end], dp[i-1][start][end] + cost2);
                }
            }

            dp[i] = move(new_dp);  // move to save memory
        }

        // Final answer = min of all dp[n-1][start][end]
        int ans = INF;
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                ans = min(ans, dp[n-1][i][j]);
        
        return ans;
    }
};
