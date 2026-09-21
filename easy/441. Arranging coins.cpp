class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int a = mid;
            int b = mid + 1;

            if (a % 2 == 0)
                a /= 2;
            else
                b /= 2;

            if (a <= n / b) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};
