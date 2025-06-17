class Solution {
  private:
    int lps(string s){
        int n = s.length();
        vector<int>ans(n);
        int i=1, len = 0;
        // this is for perfect prefix and suffix,, might vary for others
        while(i<n){
            if(s[i]==s[len]){
                len++;
                ans[i]=len;
                i++;
            }
            else{
                if(len != 0){
                    len = ans[len-1];
                }
                else{
                    ans[i] = 0;
                    i++;
                }
            }
        }
        return ans[n-1];
        
    }
  public:
    int minChar(string& s) {
       int n = s.length();
       string t = s;
       reverse(t.begin(), t.end());
       return n-lps(s+'*'+t);
    }
};
