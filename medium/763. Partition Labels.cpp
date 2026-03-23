class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mpp;
        unordered_set<char>vis;
        for(char c: s) mpp[c]++;
        // freq map is made 
        vector<int>ans;
        int last = 0;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]--;
            vis.insert(s[i]);
            if(mpp[s[i]]==0){
                vis.erase(s[i]);
                mpp.erase(s[i]);
            }
            if(vis.empty()){
                ans.push_back(i-last+1);
                last = i+1;
            }
        }
        return ans;
    }
};

// soln2 - in one pass have a frequency map, in second pass, keep a set of seen characters and og map size. keep decreasing frequency
// when 0, check cur map size diff from og and vis size. if same --> one partition. 

// soln3 similar to merge intervals 
#define pii pair<int, int>
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pii>hash;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(hash.find(s[i])==hash.end()){
                hash[s[i]] = {i, i};
            }
            else{
                hash[s[i]].second = i;
            }
        }
        vector<pii>intervals;
        for(auto it: hash) {
            intervals.push_back(it.second);
        }

        sort(intervals.begin(), intervals.end());
        vector<int>ans;
        // for(auto it : intervals) cout<<it.first << " "<<it.second<<endl;
        for(int i=1; i<intervals.size(); i++){
            // cout<<intervals[i].first << " "<<intervals[i].first<<endl;
            if(intervals[i].first < intervals[i-1].second){
                intervals[i].first = intervals[i-1].first; 
                intervals[i].second = max(intervals[i].second, intervals[i-1].second);
            }
            else{
                ans.push_back(intervals[i-1].second - intervals[i-1].first +1);
            }
        }
        ans.push_back(intervals.back().second - intervals.back().first +1);
        return ans;
    }
};
