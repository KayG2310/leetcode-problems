class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int, int>>q;
        vector<int>vis(n+1, 0);
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                q.push({i, 1});
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    int node = it.first;
                    int col = it.second;
                    int newcol = (col == 1) ? 2 : 1;
                    for(auto i: adj[node]){
                        if(vis[i]==0){
                            q.push({i, newcol});
                            vis[i] = newcol;
                        }
                        else{
                            if(vis[i]!= newcol) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
/*.    /----\
1--2.  3--4--5
*/
