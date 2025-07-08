class Solution {
private:
    bool static comp(pair<int, int>a, pair<int, int>b){
        if(a.first > b.first) return true;
        if(a.first== b.first) return a.second>=b.second;
        return false;
    }
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        int ans = 1; 
        vector<pair<int, int>>final;
        for(int i=0; i<n; i++){
            final.push_back({pos[i], speed[i]});
        }
        sort(final.begin(), final.end(), comp);
        double t = (double)(target-final[0].first)/(double)final[0].second;
        double sp = (double)final[0].second;
        double p = (double)final[0].first;
        for(int i=1; i<n; i++){
            double ti = (double)(target-final[i].first)/(double)final[i].second;
            double spi = (double)final[i].second;
            double pi = (double)final[i].first;
            if(ti<=t && pi<= p){
                // part of fleet 
                continue;
            }
            else{
                ans++;
                t = ti;
                sp = spi; p = pi;
            }
        }
        return ans;
    }
};
