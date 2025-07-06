class FindSumPairs {
public:
    vector<int>one, two;
    unordered_map<int, int>mpp; // els in nums2 are less
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        one = nums1;
        two = nums2;
        for(int i=0; i<nums2.size(); i++){
            mpp[two[i]]++;
        }
    }
    
    void add(int index, int val) {
        if(index<two.size()){
            mpp[two[index]]--;
            if(mpp[two[index]] == 0) mpp.erase(two[index]);
            two[index] += val;
            mpp[two[index]]++;
        }
    }
    
    int count(int tot) {
        int cnt = 0; 
        for(int i: one){
            cnt += mpp[tot-i];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
