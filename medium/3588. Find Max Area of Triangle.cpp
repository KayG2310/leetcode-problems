class Solution {
private:
    bool static comp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
public:
    long long maxArea(vector<vector<int>>& coords) {
        sort(coords.begin(), coords.end());
        int n = coords.size();
        int i=0, j= 0;
        long long ans = -1;
        while(i<n && j<n){
            while(j<n && coords[j][0]==coords[i][0]) j++;
            long long base = abs(coords[i][1]-coords[j-1][1]);
            long long height = max(abs(coords[0][0]-coords[i][0]), abs(coords[n-1][0]-coords[i][0]));
            ans = max(ans, base*height);
            i=j;
        }
        sort(coords.begin(), coords.end(), comp); 
        i=0, j= 0;
        while(i<n && j<n){
            while(j<n && coords[j][1]==coords[i][1]) j++;
            long long base = abs(coords[i][0]-coords[j-1][0]);
            long long height = max(abs(coords[0][1]-coords[i][1]), abs(coords[n-1][1]-coords[i][1]));
            ans = max(ans, base*height);
            i=j;
        }
        return ans==0 ? -1 : ans;
    }
};
