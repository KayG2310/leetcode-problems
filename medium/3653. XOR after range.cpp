#define mod 1000000007
// #define inti long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        for(int i=0; i<m; i++){
            int idx = queries[i][0];
            while(idx <= queries[i][1]){
                nums[idx] = ((long long)nums[idx]*(long long)queries[i][3])%(long long)mod; 
                idx += queries[i][2];
            }
        }
        int ans = 0; 
        for(int i: nums) ans = ans ^ i;
        return ans;
    }
};
