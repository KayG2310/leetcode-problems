class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // nge 
        stack<int>st;
        int n = temp.size();
        vector<int>v(n);
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(i);
                v[i] = 0;
            }
            else{
                if(temp[st.top()]<=temp[i]){
                    while(!st.empty() && temp[st.top()]<=temp[i]){
                        st.pop();
                    }
                    if(st.empty()) v[i]=0;
                    else v[i] = st.top()-i;
                    st.push(i);
                }
                else{
                    v[i] = st.top()-i;
                    st.push(i);
                }
            }
        }
        return v;
    }
};
