class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum = 0;
        vector<long long>degree(n);
        for(auto it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        priority_queue<long long>pq;
        for(int i=0; i<n; i++){
            pq.push(degree[i]);
        }
        while(!pq.empty()){
            sum += pq.top()*n;
            pq.pop();
            n--;
        }
        return sum;
    }
};
