#define pii pair<int, int>
class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int up(int u){
        if(parent[u]==u) return u;
        return parent[u] = up(parent[u]);
    }
    void uni(int u, int v){
        int pu = up(u);
        int pv = up(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        DisjointSet ds(n);
        // make all edges 
        vector<vector<int>>adj;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                adj.push_back({abs(houses[i][0]-houses[j][0])+abs(houses[i][1]-houses[j][1]), i, j});
            }
        }
        // graph has been made
        sort(adj.begin(), adj.end());
        int sum = 0;
        for(auto it: adj){
            if(ds.up(it[1])==ds.up(it[2])) continue;
            // else union time 
            sum += it[0];
            ds.uni(it[1], it[2]);
        }
        return sum;
        
    }
};
