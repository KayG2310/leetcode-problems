class Solution {
private:
    void f(vector<vector<int>>&ans, int layer, int n, int& num){
        // top left to top right
        for(int i=layer-1; i<n-layer+1; i++){
            ans[layer-1][i] = num;
            num++;
        }
        for(int i=layer; i<n-layer+1; i++){
            ans[i][n-layer] = num;
            num++;
        }
        for(int i=n-layer-1; i>=layer-1; i--){
            ans[n-layer][i] = num;
            num++;
        }
        for(int i=n-layer-1; i>layer-1; i--){
            ans[i][layer-1] = num;
            num++;
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0));
        if(n==1) return {{1}};
        if(n==2) return {{1,2}, {4,3}};
        int layers = (n%2) ? n-1 : n-2; 
        int num = 1;
        for(int i=1; i<=layers; i++){
            f(ans, i, n, num);
        }
        return ans;
        
    }
};
