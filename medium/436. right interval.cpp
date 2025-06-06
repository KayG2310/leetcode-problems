class Solution {
private: 
    bool static comp(vector<int>v1, vector<int>v2){
        return v1[0]<v2[0];
    }
    int f(int low, int high, vector<vector<int>>&v, int end){
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(v[mid][0]==end){
                return v[mid][1];
            }
            else if(v[mid][0]>end){
                ans = v[mid][1];
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            v.push_back({intervals[i][0], i});
        }
        sort(v.begin(), v.end(), comp);
        vector<int>ans;
        for(int i=0; i<n; i++){
            int low = 0, high = n-1, end = intervals[i][1];
            int x = f(low, high, v, end);
            ans.push_back(x);
        }
        return ans;
    }
};
