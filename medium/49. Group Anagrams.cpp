class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp; 
        int n = strs.size();
        for(int i=0; i<n; i++){
            string x = strs[i];
            sort(x.begin(), x.end());
            mpp[x].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
