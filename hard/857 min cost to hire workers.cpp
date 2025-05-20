class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;  // max-heap for quality
        double qSum = 0, minCost = DBL_MAX;

        for (auto& [ratio, q] : workers) {
            pq.push(q);
            qSum += q;

            if (pq.size() > k) {
                qSum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                minCost = min(minCost, qSum * ratio);
            }
        }

        return minCost;
    }
};
