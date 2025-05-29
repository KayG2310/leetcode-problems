class Solution {
public:
    vector<int> grayCode(int n) {
        int x = 1<<n;
        // another way of saying 2^n 
        vector<int>ans;
        for(int i=0; i<x; i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};
