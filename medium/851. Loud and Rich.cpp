// what I wrote 
class Solution {
private:
    void topo(vector<vector<int>>&adj, vector<int>&top, vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) topo(adj, top, vis, it);
        }
        top.push_back(node);
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // this is going to form a directed graph
        int n = quiet.size();
        vector<vector<int>>adj(n);
        for(auto it: richer){
            adj[it[1]].push_back(it[0]);
        }
        // there is edge pointing to richer -- easy for topo graph
        vector<int>top; 
        vector<int>vis(n+1);
        for(int i=0; i<n; i++){
	        if(!vis[i]){
	            topo(adj, top, vis, i);
	        }
	    }
        // get out
        map<int,int>newq;
        for(int i: top){
            newq[i] = quiet[i];
        }
        for(int i=0; i<n; i++){
            int in = top[i];
            quiet[in] = newq[in];
        }
        vector<int>mini(n);
        mini[n-1] = top[n-1];
        for(int i=n-2; i>=0; i--){
            if(quiet[i]<quiet[i+1]){
                mini[i] = top[i];
            }
            else{
                mini[i] = mini[i+1];
            }
        }
        return mini;
    }
};


// what is given 
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans(n);
        for(auto rich:richer){
            graph[rich[0]].push_back(rich[1]);
            indegree[rich[1]]++;
        }

        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i:graph[node]){
                if( quiet[ans[node]] < quiet[ans[i]])
                    ans[i] = ans[node];

                if(--indegree[i] == 0)
                    q.push(i);
            }
        }

        return ans;
    }
};
