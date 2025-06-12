class Solution {
public:
    int countDigits(int num) {
        int copy = num;
        int cnt = 0;
        while(num){
            int digit = num%10;
            if(digit && copy%digit == 0) cnt++;
            num = num/10;
        }
        return cnt;
    }
};
