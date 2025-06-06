class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        int l=0, r=0, cnt = 0;
        while(l<n && r<n){
            while(s[r] == s[l]){
                cnt++;
                r++;
            }
            if(cnt == k) return true; 
            l = r;
            cnt = 0;
        }
        return false;
    }
};
