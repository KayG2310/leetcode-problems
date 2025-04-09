class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0,  right = 0,  ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(i-1>=0) left += nums[i-1];
            right = sum-left-nums[i];
            
            if(left == right) return i;
        }
        if(left==0) return nums.size()-1;
        return -1;
    }
};
