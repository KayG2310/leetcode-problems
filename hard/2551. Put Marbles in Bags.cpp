#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        ll sum = 0;
        priority_queue<ll>maxheap;
        priority_queue<ll, vector<ll>, greater<ll>>minheap;
        for(int i=0; i<n-1; i++){
            sum = weights[i]+weights[i+1]; 
            maxheap.push(sum);
            minheap.push(sum); 
        }
        ll maxi = 0, mini = 0;
        for(int i=0; i<k-1 && !maxheap.empty(); i++){
            maxi += maxheap.top();
            maxheap.pop();
        }
        for(int i=0; i<k-1 && !minheap.empty(); i++){
            mini += minheap.top();
            minheap.pop();
        }
        return maxi-mini; 
    }
};
