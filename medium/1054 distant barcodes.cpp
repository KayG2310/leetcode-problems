class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int>freq;
        priority_queue<pair<int, int>>pq; 
        for(int i: barcodes){
            freq[i]++;
        }
        // n 
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        // n 
        vector<int>ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop(); 
            ans.push_back(p.second);
            p.first -= 1;
            if(!pq.empty()){
                auto p2 = pq.top();
                pq.pop();
                ans.push_back(p2.second);
                p2.first -= 1;
                if(p2.first >0) pq.push(p2);
            }
            if(p.first >0) pq.push(p);
        }
        return ans;
        //n * logn 

        // nlogn, sc = 2n+2n 
    }
};
