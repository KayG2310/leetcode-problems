class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        int n = banned.size(), m = para.length(); 
        unordered_map<string, int>freq;
        set<string>st(banned.begin(), banned.end());
        int i=0; string temp = ""; 
        while(i<m){
            while(i<m && tolower(para[i])>='a' && tolower(para[i])<='z'){
                temp += tolower(para[i]);
                i++;
            }
            i++;
            if(temp != "" && st.find(temp) == st.end()) freq[temp]++;
            temp = "";
        } 
        int maxi = 0; string ans = "";
        for(auto it: freq){
            if(it.second>maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};
