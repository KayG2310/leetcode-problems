// my wrong solution 
class DisjointSet{
    map<string, string>parent;
    map<string, int>size;
    
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& queries) {
        int n = queries.size();
        vector<double>ans(n, -1.0);
        map<string, double>mpp;
        int m = eq.size();
        for(int i=0; i<m; i++){
            string a = eq[i][0];
            string b = eq[i][1];
            // case 1 both first time 
            auto it1 = mpp.find(a);
            auto it2 = mpp.find(b);
            if(it1==mpp.end() && it2==mpp.end()){
                mpp[b] = 1.0;
                mpp[a] = v[i];
            }
            // case 2 b is found
            else if(it1 == mpp.end()){
                mpp[a] = v[i]*mpp[b];
            }
            else{
                mpp[b] = mpp[a]/v[i];
            }
        }
        for(int i=0; i<n; i++){
            string c = queries[i][0];
            string d = queries[i][1];
            auto it1 = mpp.find(c);
            auto it2 = mpp.find(d);
            if(it1 == mpp.end() || it2 == mpp.end()) continue;
            ans[i] = mpp[c]/mpp[d];
        }
        return ans;
    }
};
/*
a = 1.0 
b = 0.5 
c = 0.3333
d = 1.0
e = 0.25 
f = 0.2 
*/ 

// correct graph approach 
class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adj;

public:
    bool dfs(string src, string target, double& num,
             unordered_map<string, bool>& visited) {
        visited[src] = 1;
        for (auto nbr : adj[src]) {
            if (nbr.first == target) {
                num = nbr.second;
                return true;
            } else if (!visited[nbr.first]) {
                if (dfs(nbr.first, target, num, visited)) {
                    num *= nbr.second;
                    return true;
                }
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double w = values[i];
            adj[u][v] = w;
            adj[v][u] = 1.0 / w;
        }

        vector<double> res;
        for (auto& q : queries) {
            string src = q[0], dest = q[1];
            if (!adj.count(src) || !adj.count(dest)) {
                res.push_back(-1.0);
            } else if (src == dest) {
                res.push_back(1.0);
            } else {
                unordered_map<string, bool> visited;
                double result = -1.0;
                dfs(src, dest, result, visited);
                res.push_back(result);
            }
        }
        return res;
    }
};
