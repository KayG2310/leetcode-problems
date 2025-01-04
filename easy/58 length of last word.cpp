class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0, ans;
        int n = s.length();
        int i=0;
        while(i<n){
            // cnt = 0;
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i] != ' '){
                i++;
                cnt++;
                ans = cnt;
            }
            cnt = 0;
        }
        return ans;
    }
};
