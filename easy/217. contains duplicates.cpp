class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt1=0, el1 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(cnt1 == 0){
                el1 = nums[i];
            }
            if(nums[i]==el1){
                cnt1++;
                if(cnt1 >1) return true;
            }
            else{
                cnt1 = 1;
                el1 = nums[i];
            }
        }
        return false;
    }
};
