class Solution {
void f(string s, string &seq, set<string>&ans, int index, int part, int n){
    if (part == 4 && index == n){
        while(seq.back()=='.'){
            seq.pop_back();
        }
        if(count(seq.begin(), seq.end(), '.')==3)ans.insert(seq);
        return;
    }
    if (part == 4 || index == n) return;
    if(s[index]=='0'){
        seq += "0.";
        f(s, seq, ans, index+1, part+1, n);
        seq.pop_back();
        seq.pop_back();
    }
    for(int len = 1; len <= 3 && index + len <= n; len++) {
        string partStr = s.substr(index, len);
        int val = stoi(partStr);
        if (val > 255) break; // invalid part
        if (partStr[0] == '0' && partStr.length() > 1) break; // leading zero

        int oldLen = seq.length();
        seq += partStr + (part == 3 ? "" : ".");
        f(s, seq, ans, index + len, part + 1, n);
        seq.resize(oldLen); // backtrack
    }
}
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n<4 || n>12) return {};
        set<string>ans;
        
        if(n==4){
            string k = "";
            k += s[0];
            k+= '.';
            k += s[1];
            k+= '.';
            k += s[2];
            k+= '.';
            k += s[3];
            ans.insert(k);
            vector<string>res(ans.begin(), ans.end());
            return res;
        }
        string seq = "";
        f(s, seq, ans, 0, 0, n);
        vector<string>res(ans.begin(), ans.end());
        return res;
    }
};
