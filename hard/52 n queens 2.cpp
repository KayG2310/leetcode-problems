class Solution {
private:
    bool check(int row, int col, int n, vector<vector<int>>& visited) {
        for (int i = 0; i < row; i++) {
            if (visited[i][col] == 1) return false; // Same column
        }
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (visited[i][j]) return false; // Upper-left diagonal
            i--; j--;
        }
        i = row; j = col;
        while (i >= 0 && j < n) {
            if (visited[i][j]) return false; // Upper-right diagonal
            i--; j++;
        }
        return true;
    }

    int solve(int row, int n, vector<vector<int>>& visited) {
        if (row == n) return 1; // All queens are placed
        int ans = 0;
        for (int col = 0; col < n; col++) {
            if (check(row, col, n, visited)) {
                visited[row][col] = 1;   // Place queen
                ans += solve(row + 1, n, visited); // Recur to the next row
                visited[row][col] = 0;  // Backtrack
            }
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        if (n < 4) return n == 1 ? 1 : 0; // Return 1 for n=1, 0 for n<4
        vector<vector<int>> visited(n, vector<int>(n, 0));
        return solve(0, n, visited);
    }
};
 
