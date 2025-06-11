class Solution {
public:
    bool closeStrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        vector<int>f1(26);
        vector<int>f2(26);
        for(int i=0; i<n; i++){
            f1[s[i]-'a']++;
            f2[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(f1[i]==0 && f2[i] != 0) return false;
            if(f1[i]!=0 && f2[i] == 0) return false;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        for(int i=0; i<26; i++){
            if(f1[i] != f2[i]) return false;
        }
        return true;
    }
};
