class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long ans = 0;
        int i=0;
        while(i<32){
            if((1<<i)&n){
                ans = ans + pow(2, 31-i);
            }
            i++;
        }
        return ans;
    }
};
