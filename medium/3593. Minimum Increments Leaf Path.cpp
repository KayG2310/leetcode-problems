class Solution {
    vector<vector<int>> adj;
    int result = 0;
    long long dfs(int cur, int parent, vector<int>& costs){
        vector<long long> child;
        for(auto next : adj[cur]){
            if(next != parent){
                child.push_back(dfs(next, cur, costs));
            }
        }
        long long maxChild = 0;
        if(child.size() > 0){
            maxChild = *max_element(child.begin(), child.end());
            for(auto val : child){
                if(val != maxChild){
                    ++result; 
                }
            }
        }
        return maxChild + costs[cur];
    }
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& costs) {
        adj.resize(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, costs);
        return result;
    }
};
/*
adj = 0 -> {4, 1} 1-> { 2, 3}
dfs(0, -1)
child = {7, 5}


*/
