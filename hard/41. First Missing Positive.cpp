// brute force 2^31 logn
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int ans;
        for(int i=1; i<= pow(2,31)-1; i++){
            if(s.find(i) == s.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// optimal tc = O(n) , sc = O(1) 
