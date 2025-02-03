class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        int i=0, j= i+1;
        while(i<n && j<n){
            if(nums[j] > nums[j-1]){
                len = max(len, j-i+1);
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j = i+1;
            }
        }
        i=0; 
        j = i+1;
        while(i<n && j<n){
            if(nums[j] < nums[j-1]){
                len = max(len, j-i+1);
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j = i+1;
            }
        }
        return len;
    }
};
