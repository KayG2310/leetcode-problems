// brute force tc = O(x) 
class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0) return x;
        // if(x>1 && x<=4) return 2;
        for(int i=1; i<x; i++){
            if((long long)i*i > x) return i-1;
        }
        return 1;
    }
};

// optimal using binary search tc = (logx)
class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0) return x;
        // if(x>1 && x<=4) return 2;
        long long i = 1, j = x;
        while(i<=j){
            long long mid = (i+j)/2;
            if(mid*mid > x){
                j = mid-1;
            }
            else if(mid* mid == x) return mid;
            else i = mid+1;
        }
        return int(j);
    }
};
