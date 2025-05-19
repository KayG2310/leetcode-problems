class Solution {
bool findK(vector<int>&nums, int k, int sum){
    int cnt = 0;
    int i=0; 
    int n = nums.size();
    int subsum = 0;
    while(i<n){
        if(nums[i]+subsum <= sum){
            subsum += nums[i];
            i++;
            /*
                i = 1 ss = 7 
                i = 2, ss = 9
                i = 3 ss = 14 
                 cnt = 1, ss = 0, i = 3

                 10 8 
            */
        }
        else{
            cnt++;
            subsum = 0;
        }
    }
    cnt++; // 2 
    return cnt<=k;
}
public:
    int splitArray(vector<int>& nums, int k) {
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(findK(nums, k, mid)){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans; 
    }
};
