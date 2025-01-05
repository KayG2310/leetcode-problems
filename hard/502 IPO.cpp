#define pii pair<int, int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pii> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Step 1: Sort projects by capital required
        sort(projects.begin(), projects.end());
        
        // Step 2: Min-heap for capital and max-heap for profits
        priority_queue<int> maxHeap; // To store profits of feasible projects
        int index = 0;
        
        // Step 3: Iterate over k projects
        while (k > 0) {
            // Add all feasible projects (capital <= w) to the max-heap
            while (index < n && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                index++;
            }
            
            // If no feasible project is found, return current capital
            if (maxHeap.empty()) return w;
            
            // Pick the most profitable project
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }
        
        return w;
    }
};
