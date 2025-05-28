class Solution {
private:
    void dfs(vector<int>&seq, vector<vector<int>>&res, int k, int index, int n){
        if(seq.size()==k){
            res.push_back(seq);
            return;
        }
        for(int i=index; i<=n; i++){
            seq.push_back(i);
            dfs(seq, res, k, i+1, n);
            seq.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>seq;
        dfs(seq, res, k, 1, n);
        return res;
    }
};
