class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long cost = 0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq1;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq2;
        vector<int>vis(n);
        int last1 = 0, last2 = n-1;
        while(k--){
            int i=last1;
            while(i<n && pq1.size()<candidates && last1<=last2){
                if(i<n && !vis[i]){
                    pq1.push({costs[i], i});
                    vis[i] = 1;
                }
                i++;
            }
            last1 = i;
            i=last2;
            while(i>=0 && pq2.size()<candidates && last1 <= last2){
                if(i>=0 && !vis[i]){
                    pq2.push({costs[i], i});
                    vis[i] = 1; 
                }
                i--;
            }
            last2 = i;
            if(!pq1.empty() && !pq2.empty()){
                if(pq1.top().first<=pq2.top().first){
                    cost += pq1.top().first;
                    pq1.pop();
                }
                else{
                    cost += pq2.top().first;
                    pq2.pop();
                }
            }
            else{
                if(!pq1.empty()){
                    cost += pq1.top().first;
                    pq1.pop();
                }
                else if(!pq2.empty()){
                    cost += pq2.top().first;
                    pq2.pop();
                }
            }
        }
        return cost;
    }
};
