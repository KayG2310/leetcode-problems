// better O(n^2) sc = 1
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        for(int i=2; i<n; i++){
            int val = nums[i];
            int x = -1, y = -1;
            for(int j=0; j<i; j++){
                if(nums[j]<val){
                    x = j;
                }
                if(nums[j]>val){
                    y = j;
                }
                if(x!= -1 && y!=-1 && x<y)return true;
            }
        }
        return false;
    }
};
