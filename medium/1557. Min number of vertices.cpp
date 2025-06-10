class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>in(n, 0), res;
        for(auto it : edges){
            in[it[1]]++;
        }
        for (int i = 0; i < n; ++i) {
            if(in[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
