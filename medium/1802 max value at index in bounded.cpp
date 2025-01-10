class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        while(low<=high){
            long long mid = (high+low)/2;
            long long els_in_left = index;
            long long els_in_right = n-index-1;
            long long left_start = mid-els_in_left; 
            long long left_sum;
            if(left_start < 1){
                long long extra_ones = els_in_left-mid+1; 
                left_sum = ((mid-1)*mid)/2;
                left_sum += extra_ones;
            }
            else left_sum = (els_in_left*(2*left_start + els_in_left - 1))/2;
            long long right_end = mid-els_in_right;
            long long right_sum;
            if(right_end<1){
                long long extra_ones = els_in_right-mid+1; 
                right_sum = ((mid-1)*mid)/2;
                right_sum += extra_ones;
            }
            else right_sum = (els_in_right*(2*right_end + els_in_right-1))/2;
            if(left_sum+right_sum+mid > maxSum){
                high = mid-1;
            }
            else if(left_sum+right_sum+mid <= maxSum) low = mid+1;
            // else low = mid+1;
        }
        return high;
    }
};
