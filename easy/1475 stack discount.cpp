class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans;
        stack<int>s;
        for(int i=n-1; i>=0; i--){
            if(s.empty()){
                s.push(prices[i]);
                ans.push_back(prices[i]);
            } 
            else{
                if(s.top()<=prices[i]){
                    ans.push_back(prices[i]-s.top());
                    s.push(prices[i]);
                }
                else{
                    while(s.empty()==false && s.top()>prices[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(prices[i]);
                        ans.push_back(prices[i]);
                    }
                    else{
                        ans.push_back(prices[i]-s.top());
                        s.push(prices[i]);
                    }
                    
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
