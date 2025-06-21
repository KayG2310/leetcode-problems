class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int ultimate_parent(int u){
        if(parent[u]==u) return u;
        return parent[u] = ultimate_parent(parent[u]);
    }
    void unionn(int u, int v){
        int pu = ultimate_parent(u);
        int pv = ultimate_parent(v);
        if(pu == pv){
            return;
        }
        if(size[pu]>=size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n); 
        sort(edges.begin(), edges.end()); reverse(edges.begin(), edges.end());
        int index = 0, cnt = 0;
        while(index < edges.size() && edges[index][0]==3){
            int pu = ds1.ultimate_parent(edges[index][1]);
            int pv = ds1.ultimate_parent(edges[index][2]);
            if(pu == pv) cnt++;
            else{
                ds1.unionn(pu, pv);
                ds2.unionn(pu, pv);
            }
            index++;
        }
        while(index < edges.size()){
            int type = edges[index][0];
            if(type == 1){
                int pu = ds1.ultimate_parent(edges[index][1]);
                int pv = ds1.ultimate_parent(edges[index][2]);
                if(pu == pv) cnt++;
                else{
                    ds1.unionn(pu, pv);
                }
            }
            else{
                int pu = ds2.ultimate_parent(edges[index][1]);
                int pv = ds2.ultimate_parent(edges[index][2]);
                if(pu == pv) cnt++;
                else{
                    ds2.unionn(pu, pv);
                }
            }
            index++;
        }
        for(int i=1; i<=n; i++){
            ds1.parent[i] = ds1.ultimate_parent(i);
            ds2.parent[i] = ds2.ultimate_parent(i);
        }
        for(int i=2; i<=n; i++){
            if(ds1.parent[i] != ds1.parent[i-1]) return -1;
            if(ds2.parent[i] != ds2.parent[i-1]) return -1;
        }
        return cnt;
    }
};
