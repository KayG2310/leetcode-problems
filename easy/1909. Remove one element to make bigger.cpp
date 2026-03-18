class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size(), cnt = 0, p1 = -1, p2 = -1;
        if(n<3) return true; 
        for(int i=0; i<n; i++){
            if(nums[i]>p2){
                p1 = p2;
                p2 = nums[i]; 
            }
            else if(nums[i] <=p2 && nums[i] >p1){
                p2 = nums[i];
                cnt++;
            }
            else{
                cnt++;
            }
            if(cnt>1) return false;
        }
        return true;
        
    }
};
