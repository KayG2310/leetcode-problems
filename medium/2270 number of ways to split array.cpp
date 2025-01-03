class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ways = 0;
        vector<long long>presum(n);
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            presum[i] = sum;
        }
        for(int i=0; i<n-1; i++){
            if(presum[i] >= presum[n-1]-presum[i]) ways++;
        }
        return ways;
    }
}; 
