class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = 0;
            for(int val:nums){
                if(val<=mid) cnt++;
            }
            if(cnt <= mid){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
};
