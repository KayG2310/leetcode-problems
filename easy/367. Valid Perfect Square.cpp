class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num/2+1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(num%mid == 0 && mid == num/mid) return true;
            if(mid < num/mid) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
