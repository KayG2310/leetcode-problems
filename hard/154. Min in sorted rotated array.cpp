class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, ans = nums[0];
        while(low<=high){
            int mid = (high+low)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid]>nums[high]){
                // right has break off point 
                low = mid+1;
            }
            else if(nums[mid]<nums[high]){
                // left half has potential break off point 
                high = mid;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};
