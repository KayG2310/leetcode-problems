class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        int i=0, j=0;
        while(i<n && j<m){
            while(i<n && nums1[i]<nums2[j])i++;
            while(i<n && j<m && nums2[j]<nums1[i])j++;
            if(i==n || j==m) break;
            if(i<n && j<m && nums1[i]==nums2[j] && (ans.empty() || (nums1[i] != ans.back()))) ans.push_back(nums1[i]);
            if(i<n && j<m && nums1[i]<=nums2[j]) i++;
            else j++;
        }
        return ans;
    }
};
