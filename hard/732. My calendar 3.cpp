class MyCalendarThree {
    map<int, int>mpp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int cur = 0, ans = 0;
        for(auto it:mpp){
            cur += it.second;
            ans = max(ans, cur);
        }
        return ans;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
