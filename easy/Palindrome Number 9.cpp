class Solution {
public:
    bool isPalindrome(int x) {
        // approach 1, convert to string and then check
        // approach 2, make a copy and do
        int y = x;
        x = (long long) x;
        long long newcopy = 0;
        while(y>0){
            int rem = y%10;
            newcopy = newcopy*10+rem;
            y = y/10;
        }
        if(newcopy==x) return true;
        return false;
    }
};
// tc = O(number of digits) 
