class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.length(), m = b.length();
        int i = n-1, j = m-1, carry = 0;
        while(i>-1 && j>-1){
            int result = (a[i]-'0')+(b[j]-'0')+carry;
            if(result ==2){
                carry = 1;
                ans = '0'+ans;
            }
            else if(result==3){
                carry = 1;
                ans = '1'+ans;
            }
            else{
                carry = 0;
                char x = result + '0';
                ans = x+ans;
            }
            i--;
            j--;
        }
        while(i>=0){
            int result = (a[i]-'0')+carry;
            if(result ==2){
                carry = 1;
                ans = '0'+ans;
            }
            else if(result==3){
                carry = 1;
                ans = '1'+ans;
            }
            else{
                carry = 0;
                char x = result + '0';
                ans = x+ans;
            }
            i--;
            // j--;
        }
        while(j>=0){
            int result = (b[j]-'0')+carry;
            if(result ==2){
                carry = 1;
                ans = '0'+ans;
            }
            else if(result==3){
                carry = 1;
                ans = '1'+ans;
            }
            else{
                carry = 0;
                char x = result + '0';
                ans = x+ans;
            }
            // i--;
            j--;
        }
        if(carry) ans = '1'+ans;
        return ans;
    }
};
