class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited, vector<int>&r, vector<int>&c, int m, int n){
        visited[row][col] = 1;
        for(int i=0; i<4; i++){
            int nr = row+r[i];
            int nc = col+c[i];
            if(nr<m && nr>=0 && nc<n && nc>=0 && visited[nr][nc] == 0 && grid[nr][nc]=='1'){
                dfs(nr, nc, grid, visited, r, c, m, n);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        vector<int>r = {-1,1,0,0};
        vector<int>c = {0,0,1,-1};
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    dfs(i, j, grid, visited, r,c,m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
