class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1,0));
        if(k==1) return ans;
        for(int i=0; i+k-1<m; i++){
            for(int j=0; j+k-1<n; j++){
                vector<int>temp; 
                for(int p=i; p<i+k; p++){
                    for(int q=j; q<j+k; q++){
                        temp.push_back(grid[p][q]);
                    }
                }
                sort(temp.begin(), temp.end());
                int mini = temp[k*k-1]-temp[0];
                for(int ind = 1; ind < k*k; ind++){
                    if(temp[ind] != temp[ind-1])mini = min(mini, abs(temp[ind]-temp[ind-1]));
                }
                ans[i][j] = mini;
            }
        }
        return ans;
    }
}; 
