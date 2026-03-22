class Solution {
private: 
    bool static comp(string a, string b){
        if(a.length()<b.length()) return true; 
        if(a.length()==b.length()){
            return a<b;
        }
        return false;
    }
    bool f(string s, map<char, set<string>>&startsFrom, int stringindex, int m, vector<int>&dp){
        if(stringindex >= m) return true; 
        if(dp[stringindex] != -1) return dp[stringindex];
        if(startsFrom.find(s[stringindex]) == startsFrom.end()){
            return false;
        }
        bool found = false;
        for(string ss: startsFrom[s[stringindex]]){
            bool thisword = true;
            if(ss == s) continue;
            for(int i=1; i<ss.length(); i++){
                if(stringindex+i < m && s[stringindex+i]==ss[i]){
                    continue; 
                }
                else{
                    thisword = false;
                    break;
                }
            }
            if(thisword) found = found || f(s, startsFrom, stringindex+ss.length(), m, dp);
            if(found) return dp[stringindex] = true;
        }
        return dp[stringindex] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);

        // word break 
        // store words starting from each letter 
        map<char, set<string>>startsFrom; 
        for(string s: words){
            // cout<<s<<endl;
            startsFrom[s[0]].insert(s);
        }
        vector<string>ans;
        for(string s: words){
            vector<int>dp(s.length(), -1);
            if(f(s, startsFrom, 0, s.length(), dp)) ans.push_back(s);
        }
        return ans;
    }
};
/*
["cat","dog", "cats","catsdogcats","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
*/
