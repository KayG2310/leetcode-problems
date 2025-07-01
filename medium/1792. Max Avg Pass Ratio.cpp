#define ld long double
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {
        // maintain min heap of all ratios 
        priority_queue<vector<ld>>pq;
        for(auto it: classes){
            long double x = (long double)it[0];
            long double y = (long double)it[1];
            pq.push({(x+1.0)/(y+1.0) - x/y, x/y, x, y});
        }
        while(e){
            auto it = pq.top(); pq.pop();
            e--;
            ld np = it[2]+1.0;
            ld nt = it[3]+1.0; 
            pq.push({(np+1.0)/(nt+1.0) - np/nt, np/nt, np, nt});
        }
        ld ratio = 0.0; 
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            ratio += it[1];
        }
        return ratio/(ld)classes.size();
    }
};
