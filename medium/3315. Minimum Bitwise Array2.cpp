class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1e9);
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x==2) ans[i] = -1;
            else{
                for(int j =0; j<32; j++){
                    int y = ~(1<<j);
                    int m = x&y;
                    if((m|(m-1)) == x) ans[i] = min(ans[i], m-1);
                    if((m|(m+1)) == x) ans[i] = min(ans[i], m);
                }
            }
        }
        return ans;
    }
};
