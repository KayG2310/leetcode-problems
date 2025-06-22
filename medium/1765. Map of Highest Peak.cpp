class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n = w.size(), m = w[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<vector<int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(w[i][j]==1){
                    ans[i][j] = 0;
                    q.push({0, i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int>r = {-1, 1, 0, 0};
        vector<int>c = {0, 0, -1, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = it[1]+r[i];
                int nc = it[2]+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    ans[nr][nc] = it[0]+1;
                    vis[nr][nc] = 1;
                    q.push({ans[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};
