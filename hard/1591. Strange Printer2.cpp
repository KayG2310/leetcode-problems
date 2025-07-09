class Solution {
private: 
    vector<int>r = {-1, 1, 0, 0};
    vector<int>c = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& grid, int i, int j,int col, int& left, int& right, int& top, int& bot, int n, int m, vector<vector<int>>&vis){
        vis[i][j] = 1;
        if(i<top) top = i;
        if(i>bot) bot = i;
        if(j<left) left = j;
        if(j>right) right = j;
        for(int k=0; k<4; k++){
            int nr = i+r[k];
            int nc = j+c[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==col && vis[nr][nc] == 0){
                dfs(grid, nr, nc, col, left, right, top, bot, n, m, vis);
            }
        }
    }
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        set<int>mpp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp.insert(grid[i][j]);
            }
        } 
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<int>topo; 
        vector<vector<int>>graph(61);
        vector<int>indegree(61);
        // make graph
        for(auto it: mpp){
            int left = m, right = 0, top = n, bot = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == it){
                        dfs(grid, i, j, it, left, right, top, bot, n, m, vis);
                    }
                }
            }
            // cout<<left<<"--"<<right<<"--"<<top<<"--"<<bot<<"--"<<endl;
            for(int l=top; l<=bot; l++){
                for(int h=left; h<=right; h++){
                    if(grid[l][h] != it) {
                        graph[grid[l][h]].push_back(it);
                        indegree[it]++;
                    }
                }
            }
        }
        // do topo sort 
        queue<int>q;
        for(int i=1; i<62; i++){
            if(mpp.find(i) != mpp.end() && indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int it = q.front();
            q.pop();
            topo.push_back(it);
            for(auto i: graph[it]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(topo.size() != mpp.size()) return false; 
        return true;
    }
};
