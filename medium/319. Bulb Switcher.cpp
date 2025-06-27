class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        if(n==1) return n;
        return floor(pow(n, 0.5)); 
    }
};
