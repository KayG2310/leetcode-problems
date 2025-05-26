class Solution {
public:
    int titleToNumber(string s) {
        unordered_map<char, int>mpp;
        for(int i=0; i<26; i++){
            mpp['A'+i] = i+1;
        }
        int result =0;
        for(int i=0; i<s.length(); i++){
            result = result*26 + mpp[s[i]];
        }
        return result;
    }
};
