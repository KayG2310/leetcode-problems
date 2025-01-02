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
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool contains1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!contains1) return 1;
        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);
            if (value == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[value] = -abs(nums[value]);
            }
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }
        if (nums[0] > 0) {
            return n;
        }
        return n + 1;
    }
};
