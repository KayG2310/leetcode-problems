class Solution {
private:
    void f(vector<int>& cookies, int k, vector<int>&final, int n, int index, int& ans){
        if (index == n) {
            ans = min(ans, *max_element(final.begin(), final.end()));
            return;
        }
        for (int i = 0; i < k; i++) {
            final[i] += cookies[index];
            f(cookies, k, final, n, index+1, ans);
            final[i] -= cookies[index]; // back-track
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>final(k, 0);
        int n = cookies.size();
        int ans = accumulate(cookies.begin(), cookies.end(), 0);
        f(cookies, k, final, n, 0, ans);
        return ans;
    }
};
