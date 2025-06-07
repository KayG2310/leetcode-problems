class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        multiset<int, greater<int>>low;
        multiset<int>high;
        vector<double>medians;
        for(int j=0;j<nums.size();j++){
            low.insert(nums[j]);
            high.insert(*low.begin());
            low.erase(low.begin());
            if(low.size() < high.size()){
                low.insert(*high.begin());
                high.erase(high.begin());
            }
            if(j-i+1 == k){
                // window is matched. Find median and shrink it
                if(k&1)
                    medians.push_back(*low.begin());
                else
                    medians.push_back(((double)*low.begin() + (double)*high.begin())/2.0);

                if(nums[i] <= *low.begin())
                    low.erase(low.find(nums[i]));
                else
                    high.erase(high.find(nums[i]));
                    i++;
            }
        }
        return medians;
    }
};


// brute 
class Solution {
private:

void addNum(int num, priority_queue<int>&left, priority_queue<int, vector<int>, greater<int>>&right) {
    if(left.size()==0 || num <= left.top()){
        left.push(num);
        // return;
    }
    else right.push(num);

    if(right.size() > left.size()){
        left.push(right.top());
        right.pop();
    }
    else if(left.size() -1 > right.size()){
        right.push(left.top());
        left.pop();
    }
}
    
double findMedian(priority_queue<int>&left, priority_queue<int, vector<int>, greater<int>>&right) {
    int tot = left.size()+right.size();
    if(tot % 2) return left.top();
    return ((double)left.top()+(double) right.top())/2.0;
}
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j = i+k-1;
        vector<double>ans;
        priority_queue<int>left;
        priority_queue<int, vector<int>, greater<int>>right;
        while(j<nums.size()){
            for(int k=i; k<=j; k++){
                addNum(nums[k], left, right);
            }
            ans.push_back(findMedian(left, right));
            left=priority_queue<int>();
            right = priority_queue<int, vector<int>, greater<int>>();
            i++;
            j++;
        }
        return ans;
    }
};
