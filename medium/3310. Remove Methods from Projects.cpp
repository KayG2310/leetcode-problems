// dfs
class Solution {
private:
    void dfs(int node, vector<int>&visited, set<int>&defected, vector<set<int>>&directed){
        visited[node] = 1;
        defected.insert(node);
        for(auto it: directed[node]){
            if(!visited[it]) dfs(it, visited, defected, directed);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<set<int>>directed(n);
        for(auto it: invocations){
            directed[it[0]].insert(it[1]);
        }
        set<int>defected; 
        vector<int>visited(n);
        dfs(k, visited, defected, directed);
        set<int>ans;
        for(int i=0; i<n; i++){
            if(defected.find(i) == defected.end()) ans.insert(i);
        }
        vector<int>v(n); for(int i=0; i<n; i++)v[i]=i;
        for(int i=0; i<n; i++){
            if(defected.find(i) == defected.end()){
                ans.insert(i);
                // we will see if we find an infected node in this
                for(auto it: directed[i]){
                    if(defected.find(it) != defected.end()) {
                        return v; 
                    }
                }
            }
        }
        vector<int>res(ans.begin(), ans.end());
        return res;
    } 

}; 

// better data structures
class Solution {
private:
    void dfs(int node, vector<bool>& visited, vector<bool>& defected, vector<vector<int>>& directed) {
        visited[node] = true;
        defected[node] = true;
        for(int next : directed[node]) {
            if(!visited[next]) {
                dfs(next, visited, defected, directed);
            }
        }
    }
    
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> directed(n);
        for(auto& edge : invocations) {
            directed[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(n, false);
        vector<bool> defected(n, false);
        dfs(k, visited, defected, directed);
        
        // Check if any non-defected method calls a defected method
        for(int i = 0; i < n; i++) {
            if(!defected[i]) {
                for(int next : directed[i]) {
                    if(defected[next]) {
                        // Return all methods if contamination exists
                        vector<int> all(n);
                        iota(all.begin(), all.end(), 0);
                        return all;
                    }
                }
            }
        }
        
        // Return only non-defected methods
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(!defected[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
