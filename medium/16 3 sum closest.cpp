class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j = 1, k=n-1;
        int sum = INT_MAX, ans = 0;
        for(i=0; i<n-2; i++){
            j=i+1, k = n-1;
            while(j<k){
                int d = abs(target-nums[i]-nums[j]-nums[k]);
                if(d<sum){
                    ans = nums[i]+nums[j]+nums[k];
                    sum = abs(target-nums[i]-nums[j]-nums[k]);
                }
                if(nums[i]+nums[j]+nums[k] < target){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k] == target){
                    return target;
                }
                else{
                    k--;
                }
            }
        }
        return ans;

    }
};
