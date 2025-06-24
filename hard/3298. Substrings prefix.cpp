#define ll long long
class Solution {
public:
    bool isValid(map<char, int> &window, map<char, int> &target) {
        for (auto &[ch, cnt] : target) {
            if (window[ch] < cnt) return false;
        }
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        ll ans = 0;
        int i = 0, j = 0;
        map<char, int> mpp;
        for (char c : word2) {
            mpp[c]++;
        }

        map<char, int> m2;
        while (j < n) {
            m2[word1[j]]++;

            while (i <= j && isValid(m2, mpp)) {
                // all substrings from i to j, j+1 to n-1 are valid
                ans += (n - j);
                m2[word1[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};
