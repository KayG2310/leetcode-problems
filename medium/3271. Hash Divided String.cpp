class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        int n = s.length();
        int i = 0;
        while(i<n){
            int sum = 0;
            for(int j=i; j<i+k && j<n; j++)
            {
                sum += (s[j]-'a');
            }
            i+=k;
            ans += (sum%26)+'a';
        }
        return ans;
    }
};
