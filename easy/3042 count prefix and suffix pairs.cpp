class Solution {
private:
    bool f(string &s, string &t) {
    return t.find(s) == 0 && t.rfind(s) == t.length() - s.length();
}

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i=0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(f(words[i], words[j])==true) cnt++;
            }
        }
        return cnt;
    }
};
