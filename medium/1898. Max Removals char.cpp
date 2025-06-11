class Solution {
public:
    bool f(string s, string t){
        int j = 0,m=s.length(),n=t.length();
        for (int i = 0; i < n && j < m; i++)
            if (s[j] == t[i])
                j++;
        return (j == m);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string copy=s;
        int l = 0, r =removable.size();
        int ans = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            for(int i=0;i<mid;i++) copy[removable[i]]='#';
            if (f(p,copy)){
                ans = max(ans, mid);
                l = mid+1;
            }
            else{
                for(int i=0;i<mid;i++) copy[removable[i]] = s[removable[i]];
                r = mid-1;
            }
        }
        return ans;
    }
};
