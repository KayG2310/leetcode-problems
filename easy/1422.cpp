class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int left = 0, right = 0;
        if(s[0]=='0') left++;
        for(int i=1; i<n; i++) if(s[i]=='1') right++;
        int score = left+right;
        for(int i=1; i<n-1; i++){
            if(s[i]=='0'){
                left++;
            }
            else{
                right--;
            }
            score = max(score, left+right);
        }
        return score;
    }
};
// tc = 2n, sc = 1
