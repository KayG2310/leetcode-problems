class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // we find farthest 1's in 4 directions 
        // top ka i 
        // left right ka j 
        // bottom ka bhi i 
        int n = grid.size();
        int m = grid[0].size();
        int it = n, ib = -1, jl = m, jr = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    it = min(i, it);
                    ib = max(i, ib);
                    jl = min(j, jl);
                    jr = max(j, jr);
                }
            }
        }
        int x = (jr-jl+1);
        int y = (ib-it+1);
        return x*y;
    }
};
