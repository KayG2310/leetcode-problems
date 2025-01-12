class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int i = 0, n = s.length();
        while (i < n) {
            string word = "";
            while (i < n && s[i] == ' ') i++;
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if (!word.empty()) words.push_back(word);
        }

        if (words.size() != pattern.length()) return false;

        unordered_map<char, string> mpp;
        unordered_map<string, char> revMpp;

        for (int i = 0; i < pattern.length(); i++) {
            if (mpp.find(pattern[i]) != mpp.end()) {
                if (mpp[pattern[i]] != words[i]) return false;
            } else {
                mpp[pattern[i]] = words[i];
            }
            if (revMpp.find(words[i]) != revMpp.end()) {
                if (revMpp[words[i]] != pattern[i]) return false;
            } else {
                revMpp[words[i]] = pattern[i];
            }
        }
        return true;
    }
};
