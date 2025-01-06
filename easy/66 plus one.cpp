class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        digits[n-1]+=1;
        if(digits[n-1]>=10){
            digits[n-1] %= 10;
            carry = 1;
        }
        for(int i=n-2; i>=0; i--){
            digits[i] += carry;
            if(digits[i]>=10){
                digits[i] %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
