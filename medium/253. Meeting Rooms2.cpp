class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int ans = 0, cur = 0; 
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i=0, j=0, n = start.size();
        while(i<n){
            if(start[i] < end[j]) {
              // this condition can be equal as well --> read the question carefully
                cur++;
                i++;
            }
            else{
                j++; cur--;
            } 
            ans = max(ans, cur);
        }
        
        return ans;
        
    }
};
