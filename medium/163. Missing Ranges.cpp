class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &nums, int lower, int upper) {
        // code here
        int n = nums.size();
        vector<vector<int>>ans;
        if((nums[0]>lower && nums[0]>upper) || nums[n-1]<lower) return {{lower, upper}};
        // ek baar traverse krke pointers nikaal lo range ke
        int one = 0, two = n-1;
        while(nums[one]<lower) one++;
        while(nums[two]>upper) two--;
        if(nums[one]>lower) ans.push_back({lower, nums[one]-1});
        for(int i=one; i<two; i++){
            /*
            i=0 start = 15 end = 14 no push 
            i=1 start = 16 end = 19
            */
            int start = nums[i]+1;
            int end = nums[i+1]-1;
            if(start<=end){
                ans.push_back({start, end});
            }
        }
        if(nums[two]<upper) ans.push_back({nums[two]+1, upper});
        return ans;
    }
};
