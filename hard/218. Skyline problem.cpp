// my incomplete code 
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>points;
        int n = buildings.size();
        for(int i=0; i<n; i++){
            points.push_back({buildings[i][0], buildings[i][2]});
            points.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(points.begin(), points.end());
        n = points.size();
        vector<vector<int>>ans;
        set<int>prev_heights;
        int cur = 0;
        for(int i=0; i<n; i++){
            if(prev_heights.empty()){
                ans.push_back
                ans.push_back(points[i]);
                prev_heights.insert(points[i][1]);
                cur = points[i][1];
            }
            else{
                int h = points[i][1], x = points[i][0];
                if(h>cur){
                    ans.push_back({x, h});
                    cur = h;
                    prev_heights.insert(cur);
                }
                else if(h==cur){
                    ans.push_back({x, h});
                    prev_heights.erase(cur);
                }
                else{
                    cur = h;

                    prev_heights.erase(h);
                    ans.push_back({x, cur});
                }
            }
        }
    }
};


// correct code 
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> points;
        for (const auto& b : buildings) {
            points.push_back({b[0], b[2]});
            points.push_back({b[1], -b[2]});
        }
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<vector<int>> ans;
        multiset<int> heights = {0};
        int prev_max = 0;
        
        for (const auto& p : points) {
            int x = p[0];
            int h = p[1];
            
            if (h > 0) {
                heights.insert(h);
            } else {
                heights.erase(heights.find(-h));
            }
            
            int current_max = *heights.rbegin();
            if (current_max != prev_max) {
                ans.push_back({x, current_max});
                prev_max = current_max;
            }
        }
        
        return ans;
    }
};
