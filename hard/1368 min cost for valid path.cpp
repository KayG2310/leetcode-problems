class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        // Directions: right, left, down, up
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        dq.push_front({0, 0});
        cost[0][0] = 0;
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] != dir + 1);
                    
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        
                        if (grid[x][y] == dir + 1) {
                            dq.push_front({nx, ny}); // No additional cost
                        } else {
                            dq.push_back({nx, ny}); // Add 1 to the cost
                        }
                    }
                }
            }
        }
        
        return cost[m - 1][n - 1];
    }
};
