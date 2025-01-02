class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>presum(n,0);
        int cnt = 0;
        unordered_set<char>s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        for(int i=0; i<n; i++){
            if(s.find(words[i][0]) != s.end() && s.find(words[i][words[i].length()-1]) != s.end()){
                cnt++;
            }
            presum[i] = cnt;
        }
        // int m = queries.size();
        vector<int>ans;
        for(auto it: queries){
            int x = presum[it[1]]-presum[it[0]];
            int ind = it[0];
            if(s.find(words[ind][0]) != s.end() && s.find(words[ind][words[ind].length()-1]) != s.end()){
                x++;
            }
            ans.push_back(x);
        }
        return ans;
    }
};
