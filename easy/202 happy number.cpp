class Solution {
private: 
    bool f(int n, set<long long>&nums){
        long long sum = 0;
        while(n>0){
            int x=n%10;
            sum += x*x;
            n = n/10;
        }
        if(sum==1) return true;
        if(nums.find(sum)!=nums.end()) return false;        
        nums.insert(sum);
        return f(sum, nums);
    }
public:
    bool isHappy(int n) {
        set<long long>nums;
        nums.insert(n);
        return f(n, nums);
    }
};
