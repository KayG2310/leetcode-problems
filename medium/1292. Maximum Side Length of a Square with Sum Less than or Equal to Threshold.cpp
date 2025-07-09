class Solution {
private:
    bool f(int mid, int t, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& presum){
        for(int i=mid-1; i<n; i++){
            for(int j=mid-1; j<m; j++){
                int upper=0, left=0, inter=0;
                if(i-mid>=0) upper = presum[i-mid][j];
                if(j-mid>=0) left = presum[i][j-mid];
                if(i-mid>=0 && j-mid>=0) inter = presum[i-mid][j-mid];
                if(presum[i][j]-upper-left+inter <= t) return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(); 
        int m = mat[0].size();
        int low = 1, high = min(n, m); 
        int ans = 0;
        vector<vector<int>>presum(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum += mat[i][j];
                presum[i][j] = sum;
            }
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                presum[i][j] += presum[i-1][j];
            }
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(f(mid, threshold, n, m, mat, presum)){
                ans = max(mid, ans); 
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans; 
    }
};
