class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& sub, set<vector<int>>&res) {
        if (sub.size() == nums.size()) {
            res.insert(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            sub.push_back(nums[i]);
            backtrack(nums, used, sub, res);
            sub.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> sub;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, sub, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
}; 
