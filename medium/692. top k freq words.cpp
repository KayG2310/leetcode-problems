class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mpp;
        for(string s: words){
            mpp[s]--;
        }
        map<int, set<string>>mp2;
        for(auto it: mpp){
            mp2[it.second].insert(it.first);
        }
        vector<string>ans;
        for(auto it: mp2){
            ans.insert(ans.end(), it.second.begin(), it.second.end());
            if(ans.size()>k){
                while(ans.size()>k){
                    ans.pop_back();
                }
                break;
            }
        }
        return ans;
    }
};
