class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // similar to merge intervals
        int n = points.size();
        sort(points.begin(), points.end());
        for(int i=0; i<n; i++) cout<<points[i][0]<<" "<<points[i][1]<<endl;
        vector<vector<int>>temp;
        for(int i=0; i<n; i++){
            if(temp.empty()){
                temp.push_back(points[i]);
                // cout<<i<<"here"<<endl;
            }
            else{
                // cout<<i<<"here2"<<endl;
                if(temp.back()[1]>=points[i][0]){
                    // cout<<i<<"here3"<<endl;
                    auto it = temp.back();
                    temp.pop_back(); 
                    it[1] = min(it[1], points[i][1]);
                    temp.push_back(it);
                }
                else{
                    temp.push_back(points[i]);
                }
            }
        }
        return temp.size();
    }
};
