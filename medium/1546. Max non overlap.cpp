// better approach --> greedy works instead of dp
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int>hash;
        hash[0] = -1;
        set<int>ind;
        int cur = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            cur += nums[i];
            if(hash.find(cur-target) != hash.end()){
                // found before 
                int index = hash[cur-target]; 
                bool flag = false; 
                for(int k=index+1; k<i; k++){
                    if(ind.find(k)!= ind.end()) {
                        // overlapping 
                        flag = true; 
                        break;
                    }
                }
                if(!flag) ind.insert(i);
            }
            hash[cur] = i;
        }
        return ind.size();
    }
};
/*
map2 = 0, 6
-1, 0       
2, 1 
7, 2
8, 3 
12, 4
14, 5
5, 6
*/

// optimised of above 
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int>hash;
        hash[0] = -1;
        int cur = 0, ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            cur += nums[i];
            if(hash.find(cur-target) != hash.end()){
                // found before 
                ans++;
                cur = 0; 
                hash.clear();
            }
            hash[cur] = i;
        }
        return ans;
    }
};
 
