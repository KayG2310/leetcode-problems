class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j-1>=0){
                    // left neighbour 
                    matrix[i][j] = matrix[i][j]^matrix[i][j-1];
                }
                if(i-1>=0){
                    // up neighbour 
                    matrix[i][j] = matrix[i][j]^matrix[i-1][j];
                }
                if(i-1>=0 && j-1>=0){
                    // top left neighbour 
                    matrix[i][j] = matrix[i][j]^matrix[i-1][j-1];
                }
                if(pq.size()<k) pq.push(matrix[i][j]);
                else{
                    if(matrix[i][j]>= pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};
