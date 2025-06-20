class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        while(!q.empty()) q.pop();
    }
    
    int ping(int t) {
        int x = t-3000;
        while(!q.empty() && q.front()<x) q.pop();
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
