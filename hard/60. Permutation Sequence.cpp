class Solution {
private: 
    int fact(int n){
        int p = 1;
        for(int i = 2; i <= n; i++) p *= i;
        return p;
    }
public:
    string getPermutation(int n, int k) {
        vector<int> digits;
        for(int i = 1; i <= n; i++) digits.push_back(i);
        k--; 
        string res = "";

        for(int i = 0; i < n; i++) {
            int f = fact(n - 1 - i);
            int index = k / f; 
            res += to_string(digits[index]); 
            digits.erase(digits.begin() + index);
            k %= f; 
        }
        return res;
    }
};


// brute recursive way 
class Solution {
private:
    void f(string seq, int k, int n, vector<int>&vis, string &ans, int& cnt){
        if(seq.length()==n){
            return;
        }
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vis[i] = 1;
                seq += to_string(i);
                if(seq.length()==n){
                    cnt++;
                    if(cnt == k){
                        ans = seq;
                        break;
                    }
                }
                f(seq, k, n, vis, ans, cnt);
                seq.pop_back();
                vis[i] = 0;
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        vector<int>vis(n+1);
        string ans; int cnt = 0;
        f("", k, n, vis, ans, cnt);
        return ans;
    }
};
