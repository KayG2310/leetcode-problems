#define ll long long
class Solution {
private:
    bool check(int mid, vector<int>& p, int m) {
        int count = 1;  
        int last_pos = p[0];
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - last_pos >= mid) {
                count++;
                last_pos = p[i];
            }
            if (count >= m) return true; 
        }
        return false;
    }   

public:
    int maxDistance(vector<int>& p, int m) {
        int n = p.size();
        sort(p.begin(), p.end());
        int low = 1, high = p[n-1]-p[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid, p, m)){
                ans = max(ans, mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};
