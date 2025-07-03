class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(5001, 0); 
        // first linear traversal 
        for(int i: nums)hash[i]++; 
        int k = 5000;
        while(k>=0 &&hash[k]==0)k--;
        for(int i=1; i<n; i+=2){
            nums[i] = k;
            hash[k]--;
            while(k>=0 &&hash[k]==0)k--;
        }
        int j =0;
        while(hash[j] == 0) j++;
        for(int i=0; i<n; i+=2){
            nums[i] = j;
            hash[j]--;
            while(j<=k && hash[j]==0) j++;
        }
        
    }
};
