class Solution {
public:
    int minSwaps(vector<int>& v) {
        int n = v.size();
        for(int i = 0; i < n; i++) {
            v[i] = v[i] % 2;
        }
        int ones = 0, zeros = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) ones++;
            else zeros++;
        }
        if ((n % 2 == 0 && ones != zeros) || 
            (n % 2 == 1 && abs(ones - zeros) != 1)) {
            return -1;
        }
        int ans_1 = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                ans_1 += abs(j - i);
                j += 2; 
            }
        }
        int ans_0 = 0;
        int k = 0; 
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                ans_0 += abs(k - i);
                k += 2; 
            }
        }
        if (n % 2 == 0) {
            return min(ans_1, ans_0);
        }
        else {
            if (ones > zeros) {
                return ans_1;
            }
        }
        return ans_0;
    }
};
