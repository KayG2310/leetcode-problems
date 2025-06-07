class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mpp;
        unordered_set<char>vis;
        for(char c: s) mpp[c]++;
        // freq map is made 
        vector<int>ans;
        int last = 0;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]--;
            vis.insert(s[i]);
            if(mpp[s[i]]==0){
                vis.erase(s[i]);
                mpp.erase(s[i]);
            }
            if(vis.empty()){
                ans.push_back(i-last+1);
                last = i+1;
            }
        }
        return ans;
    }
};
