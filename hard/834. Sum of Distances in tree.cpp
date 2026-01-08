class Solution {
private: 
    int fill_node_count(vector<int>&node_count, vector<vector<int>>&adj, int node, int parent){
        int cnt = 1;
        for(auto it : adj[node]){
            if(it == parent) continue;
            cnt += fill_node_count(node_count, adj, it, node);
        }
        return node_count[node] = cnt;
    }
    void fill_root_ans(vector<vector<int>>&adj, vector<int>&answer){
        int cur = 1, ans = 0; 
        queue<pair<int, int>>q;
        q.push({0, -1}); 
        while(!q.empty()){
            int k = q.size();
            for(int i=0; i<k; i++){
                int node = q.front().first; 
                int parent = q.front().second;
                q.pop();
                for(auto it: adj[node]){
                    if(it == parent) continue;
                    q.push({it, node});
                    ans += cur;
                }
            }
            cur++;
        }
        answer[0] = ans;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>answer(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>node_count(n, 0);
        fill_node_count(node_count, adj, 0, -1); // filled up
        fill_root_ans(adj, answer); 
        queue<pair<int, int>>q;
        for(auto it: adj[0]) q.push({it, 0}); 
        while(!q.empty()){
            int ans = 0;
            int node = q.front().first, parent = q.front().second; 
            q.pop();
            ans = answer[parent]; 
            ans -= 2*node_count[node]; 
            ans += n; 
            answer[node] = ans; 
            for(auto it: adj[node]){
                if(it == parent) continue;
                q.push({it, node});
            }
        }
        return answer;
    }
};
