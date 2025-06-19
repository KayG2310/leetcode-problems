/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& inn) {
        int n = inn.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            v.push_back({inn[i].start, 1});
            v.push_back({inn[i].end, 0});
        }
        sort(v.begin(), v.end());
        int cnt = 0, ans = 0;
        for(int i=0; i<2*n; i++){
            if(v[i].second==1){
                cnt++;
                ans = max(ans, cnt);
            }
            else cnt--;
        }
        return ans;
    }
};
/*
1 0
5 0
5 1
*/
