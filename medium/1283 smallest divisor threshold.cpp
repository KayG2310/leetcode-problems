class Solution {
private:
    bool f(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        for(int &val: nums){
            sum += ceil((float)val/(float)divisor);
            if(sum > threshold) return false;
        }
        return true;
        
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = (low+high)/2;
            if(f(nums, threshold, mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
