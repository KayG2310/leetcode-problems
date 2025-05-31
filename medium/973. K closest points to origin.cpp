class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(auto it: points){
            int dist = pow(it[0], 2)+pow(it[1], 2);
            pq.push({dist, it[0], it[1]});
        }
        while(ans.size()<k){
            auto it = pq.top();
            pq.pop();
            ans.push_back({it[1], it[2]});
        }
        return ans;
    }
};
