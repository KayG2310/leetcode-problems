// wrong answer 41/76
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = nums[n-1]-nums[0];
        for(int i=0; i<n; i++){
            while(nums[i]%2 == 0) nums[i]/=2;
        }
        sort(nums.begin(), nums.end());
        diff = min(diff, nums[n-1]-nums[0]);
        int x = nums[0];
        nums[0]*=2;
        diff = min(diff, abs(nums[n-1]-nums[0]));
        return diff;
    }
};
/*
3 4 5 diff = 2 
1 3 5  diff = 4
2 3 5 diff = 3

*/

// attempt 2 61/76
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i: nums){
            st.insert(i);
        }
        int diff = *st.rbegin() - *st.begin();
        if(diff == 0) return 0;
        // while biggest is even, shrink 
        while(*st.rbegin()%2==0 && *st.rbegin()/2>=*st.begin()){
            int x = *st.rbegin();
            st.erase(x); 
            x = x/2;
            st.insert(x);
        }
        // while smallest is odd, inc
        while(*st.begin()%2 && *st.begin()*2<=*st.rbegin()){
            int x = *st.begin();
            st.erase(x); 
            x = x*2;
            st.insert(x);
        }
        diff = min(diff, *st.rbegin() - *st.begin());
        return diff;
    }
};
/*
3 4 5
*/ 

// attempt 3 --> correct 
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        priority_queue<int>pq;
        for(int i=0; i<n; i++){
            while(nums[i]%2) nums[i]*=2;
            mini = min(mini, nums[i]);
            pq.push(nums[i]);
        }
        int diff = pq.top()-mini; 
        while(pq.top()%2==0){
            int i = pq.top();
            pq.pop();
            i = i/2; 
            if(i<mini) mini = i;
            pq.push(i);
            diff = min(diff, pq.top()-mini);
        }
        return diff;
    }
};
