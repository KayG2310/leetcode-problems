class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // int len = 1;
        int ans = 0; int sum = 0;
        int n = nums.size();
        int i=0, j= i+1; ans = nums[i], sum = nums[i];
        while(i<n && j<n){
            if(nums[j]>nums[j-1]){
                sum += nums[j];
                ans = max(ans, sum );
                j++;
            }
            else{
                i=j;
                j = i+1;
                sum = nums[i];
            }
        }
        return ans; 
    }
};
