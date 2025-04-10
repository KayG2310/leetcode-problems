class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int lm = height[left], rm = height[right];
        int ans = 0;
        while(left < right){
            if(lm <= rm){
                left++;
                lm = max(lm, height[left]);
                ans += lm-height[left];
            }
            else{
                right--;
                rm = max(rm, height[right]);
                ans += rm-height[right];
            }
        }
        return ans;
    }
};
