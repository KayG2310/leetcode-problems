class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(); // rows
        int n = mat[0].size(); // columns
        int k = arr.size();
        // range 1 to m*n 
        unordered_map<int, pair<int, int>>mpp;
        vector<int>rows(m,0);
        vector<int>cols(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mpp[mat[i][j]] = {i, j};
            }
        }
        for(int i=0; i<k; i++){
            int x = arr[i];
            auto p = mpp[x]; // row and col corresponding to that color 
            rows[p.first]++;
            cols[p.second]++;
            if(rows[p.first] == n || cols[p.second] == m){
                return i;
            }
        }
        return -1;
    }
};
