class Solution {
private:
    double p(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        double ans = 1;
        if(n%2 == 0){
            ans = ans*myPow(x*x, n/2);
        }
        else{
            ans = ans*x*myPow(x, n-1);
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if(n>=0) return p(x, n);
        if(n==INT_MIN && x != 1.0 && x != -1.0) return 0.0;
        long long yy = (long long)n;
        double y = p(x, -yy);
        return 1.0/y;      
    }
};
