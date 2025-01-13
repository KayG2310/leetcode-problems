// brute force approach 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it: mpp){
            int x = it.second.size();
            if(x<2) continue;
            for(int i=0; i<x-1; i++){
                if(it.second[i+1]-it.second[i]<=k) return true;
            }
            // if(it.second[1]-it.second[0]<=k) return true;
        }
        return false;
    }
};

// better --> 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]] = i;
            }
            else{
                if(i-mpp[nums[i]] <=k) return true;
                else mpp[nums[i]] = i;
            }
        }
        return false;
    }
};
