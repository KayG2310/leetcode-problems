class Solution {
private:
    bool check(vector<int>&nums, int k, int mid){
        int cnt = 0;
        int i=0, n = nums.size();
        while(i<n){
            while(i<n && nums[i]>mid) i++;
            if(i<n){
                cnt++;
                i+=2;
            }
        }
        if(cnt>=k) return true;
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
