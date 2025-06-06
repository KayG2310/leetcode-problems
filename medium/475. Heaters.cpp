class Solution {
private:
    bool f(int mid, vector<int>& houses, vector<int>& heaters){
        for(int house : houses){
            // Find first heater >= house - mid
            auto it = lower_bound(heaters.begin(), heaters.end(), house - mid);
            if (it == heaters.end() || abs(*it - house) > mid) {
                // Check if heater before *it could’ve worked
                if (it == heaters.begin() || abs(*(--it) - house) > mid) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0, high=1e9, ans = 1e9;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(f(mid, houses, heaters)){
                ans = min(ans, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
