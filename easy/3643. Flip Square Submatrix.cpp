class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int lowx = x, highx = x+k-1; 
        while(lowx < highx){
            for(int j=y; j<y+k; j++){
                swap(grid[lowx][j], grid[highx][j]);
            }
            lowx++;
            highx--;
        }
        return grid;
    }
};
