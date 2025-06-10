// recursive code n3
class Solution {
private:
    int f(int i, int j, vector<int>&arr, unordered_map<int, int>&mpp){
        int el = arr[j]-arr[i];
        if(mpp.find(el) != mpp.end()){
            int k = mpp[el];
            if(k>=i) return 2;
            return 1+f(k, i, arr, mpp);
        }
        return 2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]=i;
        }
        int len = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]-arr[i]>=arr[i] || mpp.find(arr[j]-arr[i]) == mpp.end()) continue;
                len = max(len, f(i, j, arr, mpp));
            }
        }
        return len;
    }
};


// memoized 
class Solution {
private:
    int f(int i, int j, vector<int>&arr, unordered_map<int, int>&mpp,vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        int el = arr[j]-arr[i];
        if(mpp.find(el) != mpp.end()){
            int k = mpp[el];
            if(k>=i) return dp[i][j]=2;
            return dp[i][j]=1+f(k, i, arr, mpp, dp);
        }
        return dp[i][j]=2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]=i;
        }
        int len = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]-arr[i]>=arr[i] || mpp.find(arr[j]-arr[i]) == mpp.end()) continue;
                len = max(len, f(i, j, arr, mpp, dp));
            }
        }
        return len;
    }
};

// tabulation 
class Solution {

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]=i;
        }
        int len = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, 2));

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]-arr[i]>=arr[i] || mpp.find(arr[j]-arr[i]) == mpp.end()) continue;
                int el = arr[j]-arr[i];
                if(mpp.find(el) != mpp.end()){
                    int k = mpp[el];
                    if(k>=i) dp[i][j]=2;
                    else dp[i][j]=1+dp[k][i];
                }
                else dp[i][j]=2;
                len = max(len, dp[i][j]);
            }
        }
        return len<=2 ? 0: len;
    }
};
