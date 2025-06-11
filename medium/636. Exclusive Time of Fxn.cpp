class Solution {
public:
   vector<int> exclusiveTime(int n, vector<string>& logs) {
       vector<int>ans(n,0);
       stack<vector<int>>st; //{id,st time, process time}
       for(auto v:logs){
           stringstream ss(v);
           vector<int>parts;
           string token;
            while(getline(ss, token, ':')) {
               if(token == "start"){
                   parts.push_back(0);
               }
               else if(token == "end"){
                   parts.push_back(1);
               }
               else{
                   parts.push_back(stoi(token));
               }
           }
           int id = parts[0];
           int sore = parts[1];
           int ltime = parts[2];
           if(sore==0){
               if(!st.empty()){
                   auto w = st.top();
                   st.pop();
                   w[2] += ltime-w[1];
                   st.push(w);
               }
               st.push({id,ltime,0});
           }
           if(sore){
               auto w = st.top();
               st.pop();
               int id1 = w[0];
               int stime1 = w[1];
               int ptime1 = w[2];
               int tpt = ptime1+(ltime-stime1+1);
               ans[id1]+=tpt;
               if(!st.empty()){
                   auto y = st.top();
                   st.pop();
                   y[1] = ltime+1;
                   st.push(y);
               }
           }
       }
       return ans;
   }
};
