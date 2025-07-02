class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j=3;
        int n=nums.size();
        if(j>=n-1) return 0;
        int ans = nums[n-1]-nums[j];
        j = n-4;
        if(j<=0) return 0;
        ans = min(ans, nums[j]-nums[0]);
        // 2 big + 1 small 
        j=2; int k = n-2; 
        ans = min(ans, nums[k]-nums[j]);
        // 1 small 2 big
        j = 1, k = n-3; 
        ans = min(ans, nums[k]-nums[j]);
        return ans;
    }
};
/*
ans = 35
19 37 57 59 72 75 75 94 


*/
