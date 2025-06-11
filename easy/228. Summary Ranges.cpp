class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;

        int j = 0; // Start of range
        for (int i = 1; i <= n; ++i) {
            // Either end of list or break in sequence
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (j == i - 1)
                    ans.push_back(to_string(nums[j])); // Single element
                else
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i - 1])); // Range
                j = i; // Start of new range
            }
        }
        return ans;
    }
};
