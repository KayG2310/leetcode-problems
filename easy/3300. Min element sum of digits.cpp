class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 45; 
        for(int i: nums){
            int cnt = 0;
            while(i){
                cnt += i%10; 
                i = i/10;
            }
            ans = min(cnt, ans);
        }
        return ans;
    }
};
