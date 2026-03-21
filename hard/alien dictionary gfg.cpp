class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        if(n==1){
            string res = "";
            set<char>seen;
            for(int i=0; i<words[0].length(); i++){
               if(seen.find(words[0][i])==seen.end()) {
                   res += words[0][i];
                   seen.insert(res.back());
               }
            }
            return res;
        }
        vector<vector<int>>adj(26);
        vector<pair<int, int>>indegree(26, {0,0});
        queue<int>q;
        for(int i=1; i<n; i++){
            int m1 = words[i].length();
            int m2 = words[i-1].length();
            int j = 0, fl = 1; 
            while(j<m1 && j<m2){
                indegree[words[i-1][j]-'a'].second = 1;
                indegree[words[i][j]-'a'].second = 1;
                if(fl && words[i][j]!= words[i-1][j]){
                    adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                    indegree[words[i][j]-'a'].first++;
                    // break; 
                    fl = 0;
                }
                j++;
            }
            while(j<m1){
                indegree[words[i][j]-'a'].second = 1; j++;
            }
            while(j<m2){
                if(fl) return "";
                indegree[words[i-1][j]-'a'].second = 1; j++;
            }
        }
        string ans = "", ans2 = "";
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(indegree[i].first==0 && indegree[i].second == 1) q.push(i);
            cnt += indegree[i].second;
            ans2 += (i+'a');
        }
        while(!q.empty()){
            ans += (q.front()+'a');
            for(auto it: adj[q.front()]){
                indegree[it].first--;
                if(indegree[it].first==0) q.push(it);
            }
            q.pop();
        }
        // cout<<ans;
        if(ans.length() == cnt) return ans;
        return "";
    }
};
