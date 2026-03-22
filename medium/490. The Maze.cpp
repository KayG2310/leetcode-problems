class Solution {
private:
    void dfs(int row, int col) {
        if (visited[row][col]) return;
        visited[row][col] = true;
        if (row == destination[0] && col == destination[1]) return;
        vector<int> directions = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int nr = directions[k];
            int nc = directions[k + 1];
            while (row + nr >= 0 && row + nr < rows && col + nc >= 0 && col + nc < cols && maze[row + nr][col + nc] == 0) {
                row += nr;
                col += nc;
            }
            dfs(row, col);
        }
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        dfs(start[0], start[1]);
        return visited[destination[0]][destination[1]];
    }
};
