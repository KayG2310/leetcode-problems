class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ansleft = 0, ansright = minutes - 1, corr = 0;
        int n = customers.size();
        int i = 0, j = 0, cur = 0;

        if(minutes >= n) return accumulate(customers.begin(), customers.end(), 0);

        // initial window of size `minutes`
        while(j < minutes){
            cur += customers[j] * grumpy[j];
            j++;
        }
        corr = cur;

        while(j < n){
            cur -= customers[i] * grumpy[i];
            cur += customers[j] * grumpy[j];
            if(cur > corr){
                corr = cur;
                ansleft = i + 1;
                ansright = j;
            }
            i++;
            j++;
        }

        int ans = 0;
        for(int k = 0; k < n; ++k){
            if(!grumpy[k] || (k >= ansleft && k <= ansright))
                ans += customers[k];
        }
        return ans;
    }
};
