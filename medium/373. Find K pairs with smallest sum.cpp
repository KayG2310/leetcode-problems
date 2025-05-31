class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        pq.push({nums1[0]+nums2[0], 0, 0, nums1[0], nums2[0]});
        set<pair<int, int>>visited;
        visited.insert({0,0});
        while(!pq.empty() && ans.size()<k){
            auto it = pq.top();
            ans.push_back({it[3], it[4]});
            pq.pop();
            if(it[1]+1<n && visited.find({it[1]+1, it[2]}) == visited.end()){
                pq.push({nums1[it[1]+1]+nums2[it[2]], it[1]+1, it[2], nums1[it[1]+1], nums2[it[2]]});
                visited.insert({it[1]+1, it[2]});
            }
            if(it[2]+1<m && visited.find({it[1], it[2]+1}) == visited.end()){
                pq.push({nums1[it[1]]+nums2[it[2]+1], it[1], it[2]+1, nums1[it[1]], nums2[it[2]+1]});
                visited.insert({it[1], it[2]+1});
            }
        }
        return ans;
    }
}; 
