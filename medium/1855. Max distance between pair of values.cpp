class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = n-1, j = m-1, ans = 0;
        while(i>=0 && j>=0){
            while(i>=0 && nums1[i]<= nums2[j]){
                i--;
                if(i+1<=j) ans = max(ans, abs(j-i-1));
            }
            j--;
        }
        return ans;
    }
};
