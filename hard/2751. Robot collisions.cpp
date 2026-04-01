class Solution {
private:
    bool static comp(pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        vector<int>ans;
        int n = positions.size();
        stack<vector<int>>st;
        vector<vector<int>>v;
        for(int i=0; i<n; i++){
            int dir = 0;
            if(directions[i]=='R') dir = 1;
            else dir = -1;
            v.push_back({positions[i], health[i],dir, i});
        }
        /*
        v = {3,46,-1,0} {47,26,1,1}
        sort --> {3,46,-1,0} {47,26,1,1}
        */
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            if(st.empty()) st.push({v[i][1], v[i][2], v[i][3]});
            else{
                while(!st.empty() && st.top()[1]==1 && v[i][2]==-1 && v[i][1]> st.top()[0]){
                    // opp direction 
                    st.pop();
                    v[i][1]--;
                }
                if(st.empty()) st.push({v[i][1], v[i][2], v[i][3]});
                else if((st.top()[1]== 1 && v[i][2] != -1) || (st.top()[1]!= 1 && v[i][2] == -1) || (st.top()[1] == -1 && v[i][2]==1)) st.push({v[i][1], v[i][2], v[i][3]});
                else if(st.top()[0] == v[i][1]) st.pop();
                else if(st.top()[0] > v[i][1]) st.top()[0]--;
            }
        }
        /*
        i=0 
        st = {46,-1,0}
        i=1 
        st = {15,1,2} 
        i=2 
        i=3 

        */
        vector<pair<int, int>>temp;
        while(!st.empty()){
            temp.push_back({st.top()[0], st.top()[2]});
            st.pop();
        } 
        sort(temp.begin(), temp.end(), comp);
        for(auto it : temp){
            ans.push_back(it.first);
        }
        return ans;
    }
};
