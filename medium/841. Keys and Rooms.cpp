class Solution {
private:
    void dfs(int index, vector<vector<int>>& rooms, vector<int>&vis){
        vis[index] = 1;
        for(auto it: rooms[index]){
            if(!vis[it]){
                dfs(it, rooms, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n+1, 0);
        dfs(0, rooms, vis);
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
