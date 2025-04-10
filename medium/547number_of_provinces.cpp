class Solution {
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for(int neighbor : adjList[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public: 
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        
        // Build the adjacency list from the isConnected matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j]) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);  // because it's undirected
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adjList, visited);
                cnt++;
            }
        }

        return cnt;
    }
};
