#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 1) {
                            dq.push_back({nx, ny});
                        } else {
                            dq.push_front({nx, ny});
                        }
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
