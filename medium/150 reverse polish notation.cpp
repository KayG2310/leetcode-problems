class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans = 0;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(a+b);
                }
                else if(tokens[i]=="-"){
                    st.push(b-a);
                }
                else if(tokens[i]=="*"){
                    st.push(b*a);
                }
                else{
                    st.push(b/a);
                }
            }
            else{
                bool neg = false;
                if(tokens[i][0]=='-'){
                    neg = true;
                }
                int num = 0;
                for(int j=0; j<tokens[i].length(); j++){
                    if(neg && j==0) continue;
                    num = num*10 + ((char)tokens[i][j]-'0');
                }
                if(neg) {
                    st.push(-num);
                    // cout<<-num<<endl;
                }
                else {
                    st.push(num);
                    // cout<<num<<endl;
                }
            }
        }
        return st.top();
    }
};
