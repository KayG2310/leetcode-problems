class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegrees(n);
        for(auto it: edges){
            indegrees[it[1]]++;
        }
        int cnt = 0, ans = -1, index = 0;
        for(int i: indegrees){
            if(i==0){
                cnt++;
                ans = index;
            }
            index++;
        }
        if(cnt>1 || cnt == 0) return -1;
        return ans;
    }
};
