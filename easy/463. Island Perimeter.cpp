class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>r = {-1, 1, 0, 0};
        vector<int>c = {0, 0, -1, 1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    int temp = 4;
                    for(int ii=0; ii<4; ii++){
                        int nr = i+r[ii];
                        int nc = j+c[ii];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]){
                            temp--;
                        }
                    }
                    cnt += temp;
                }
            }
        }
        return cnt;
    }
};
