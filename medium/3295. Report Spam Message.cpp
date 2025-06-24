class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {
        set<string>st;
        for(auto s: banned) st.insert(s);
        int cnt = 0;
        for(string s: message){
            if(st.find(s) != st.end()) cnt++;
            if(cnt ==2) return true;
        }
        return false;
    }
};
