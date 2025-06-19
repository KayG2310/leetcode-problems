class Solution {
  private:
    bool dfs(int node, vector<int>&vis, vector<set<int>>&arr, int parent){
        vis[node] = 1;
        for(auto it: arr[node]){
            if(!vis[it]){
                if(dfs(it, vis, arr, node)) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
  public:
    int isTree(int n, int m, vector<vector<int>> &a) {
        vector<int>vis(n); 
        // make adjacency list 
        vector<set<int>>arr(n);
        for(int i=0; i<m; i++){
            int u = a[i][0];
            int v = a[i][1];
            if(arr[u].find(v)==arr[u].end()){
                arr[u].insert(v);
            }
            else return 0; // multiple edges
            if(arr[v].find(u)==arr[v].end()){
                arr[v].insert(u);
            }
            else return 0;
        }
        
        // step 2 check dfs for cycle 
        bool x = dfs(0, vis, arr, -1);
        if(x) return 0;
        for(int i=0; i<n; i++) if(!vis[i]) return 0;
        return 1;
    }
};
