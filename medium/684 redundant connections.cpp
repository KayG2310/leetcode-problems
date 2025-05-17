class DisjointSet{
private:
    vector<int>parent;
    vector<int>size;

public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);   

        for(int i=0; i<n; i++){
            parent[i] = i;
        } 
    }
    int up(int u){
        if(parent[u] == u) return u;
        return parent[u] = up(parent[u]); // path compression
    }
    void ubs(int u, int v){
        // int u1 = up(u);
        int u1 = up(u);
        int u2 = up(v);


        if(u1==u2) return;
        if(size[u1]>=size[u2]){
            parent[u2] = u1;
            size[u1]+=size[u2];
        }
        else{
            parent[u1] = u2;
            size[u2] += size[u1];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(1000);
        vector<int>ans;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.up(u)==ds.up(v)){
                ans = it;
            }
            else{
                ds.ubs(u, v);
            }
        }
        return ans;
    }
};
/*

*/
