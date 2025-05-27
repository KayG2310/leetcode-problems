class Solution {
private:
    string f(string s1, string s2){
        int n = s1.length()-1, m = s2.length()-1;
        string res="";
        int carry = 0;
        while(n>=0 && m>=0){
            int r = (s1[n]-'0')+(s2[m]-'0');
            r += carry;
            res = (char)(r%10 + '0')+res;
            carry = r/10;
            n--;
            m--;
        }
        while(n>=0){
            int r = (s1[n]-'0')+carry;
            res = (char)(r%10 + '0')+res;
            carry = r/10;
            n--;
        }
        while(m>=0){
            int r = (s2[m]-'0')+carry;
            res = (char)(r%10 + '0')+res;
            carry = r/10;
            m--;
        }
        if(carry) res = (char)(carry+'0')+res;
        return res;

    }
public:
    string multiply(string num1, string num2) {
        int n = num1.length()-1, m = num2.length()-1, carry = 0, cnt = 0;
        vector<string>v;
        for(int i=m; i>=0; i--){
            carry = 0;
            string result = "";
            for(int j = n; j>=0; j--){
                int x = (num1[j]-'0')*(num2[i]-'0');
                x += carry;
                result = (char)(x%10 + '0')+result;
                carry = x/10;
                
            }
            if(carry) result = (char)(carry+'0')+result;
            for(int k=0; k<cnt; k++){
                result.push_back('0');
            }
            cnt++;
            v.push_back(result);
        }
        string ans = v[0];
        for(int i=1; i<v.size(); i++){
            ans = f(ans, v[i]);
        }
        // string copy=ans;
        reverse(ans.begin(), ans.end());
        while(ans != "" && ans.back()=='0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans=="") return "0";
        return ans;
    }
};
