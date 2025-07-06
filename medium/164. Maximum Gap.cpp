// optimal code using bucket sort 
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int m = max(1, (high - low) / (n - 1));
        int cnt = (high - low) / m + 1;
        vector<int> bucketMin(cnt, INT_MAX), bucketMax(cnt, INT_MIN);
        vector<bool> bucketUsed(cnt, false);
        for (int num : nums) {
            int idx = (num - low) / m;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            bucketUsed[idx] = true;
        }
        int maxGap = 0, prev = low;
        for (int i = 0; i < cnt; ++i) {
            if (!bucketUsed[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        return maxGap;
    }
};

// brute force 
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        int ans = 0;
        for(int i=1; i<n; i++) ans = max(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
/*
71 29 38
71 38 29 


*/
