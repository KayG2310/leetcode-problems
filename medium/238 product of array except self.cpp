class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1, cntzero = 0, actual_product = 1;
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cntzero++;
            }
            else{
                product *= nums[i];
                // actual_product *= nums[i];
            }
        }
        if(cntzero == n || cntzero > 1) return ans;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans[i] = product;
            }
            else{
                if(cntzero > 0) ans[i] = 0;
                else ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
