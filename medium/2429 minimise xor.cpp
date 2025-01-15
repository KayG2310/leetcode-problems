class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbits = __builtin_popcount(num2);
        int bitsone = __builtin_popcount(num1);

        if (setbits == bitsone) return num1;

        if (setbits > bitsone) {
            int x = num1, bit = 0, cnt = 0;
            while (cnt + bitsone < setbits) {
                if ((x & (1 << bit)) == 0) {
                    x |= (1 << bit);
                    cnt++;
                }
                bit++;
            }
            return x;
        } else {
            int x = num1, bit = 0, cnt = 0;
            while (bitsone - cnt > setbits) {
                if ((x & (1 << bit)) != 0) {
                    x &= ~(1 << bit);
                    cnt++;
                }
                bit++;
            }
            return x;
        }
        return num1;
    }
};
