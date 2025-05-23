class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i=0, j=0;
        while(i<n && j<m){
            if(t[j]==s[i]) {
                i++;
                j++;
            }
            else j++;
        }
        if(i<n) return false;
        return true;
    }
};
