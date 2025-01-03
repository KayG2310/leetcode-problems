class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size()==1 && nums[0] == val) nums = {};

        int n = nums.size();
        int i=0, j = 0, cnt2 = 0;
        for(int it:nums){
            if(it == val) cnt2++;
        }
        if(cnt2 == n){
            nums.clear();
            return 0;
        }
        while(i<n && j<n){
            while(j<n && nums[j] != val) j++;
            while(i<n && nums[i] != val){
                i++;
            }
            while(j<n && nums[j]==val) j++;
            if(i<n && j<n) {
                swap(nums[i], nums[j]);
                
            }
        }
        return n-cnt2;

    }
};
