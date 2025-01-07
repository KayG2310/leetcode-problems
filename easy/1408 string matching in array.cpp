class Solution {
private:
    bool check(string &s, string &t){
        int i = 0, j= 0;
        if(s.length() > t.length()) return false;
        // bool flag = false;
        for(int i=0; i<t.length(); i++){
            if(t[i]==s[0]){
                bool flag = true;
                for(int j=1; j<s.length(); j++){
                    if(t[i+j] != s[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }
        }
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(check(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
}; 
