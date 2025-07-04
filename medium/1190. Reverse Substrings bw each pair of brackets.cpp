class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        int n = s.length();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]>='a' && s[i]<='z') st.push(s[i]);
            else{
                string temp = "";
                while(!st.empty() && st.top()!='('){
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                for(char c: temp) st.push(c);
            }
        }
        while(!st.empty()) {
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
