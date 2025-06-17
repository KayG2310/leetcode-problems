// better approach --> using deque O(n^2)  
class Solution {
  private:
    int f(int k, vector<int>&arr, int& n){
        int maxi = 0;
        deque<int>dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front()<= i-k) dq.pop_front();
            while(!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)  maxi = max(maxi, arr[dq.front()]);
        }
        return maxi;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>ans(n);
        ans[0] = *max_element(arr.begin(), arr.end());
        ans[n-1] = *min_element(arr.begin(), arr.end());
        for(int size=2; size<n; size++){
            int x = f(size, arr, n);
            ans[size-1] = x;
        }
        return ans;
    } 

// optimal approach 
class Solution {
  private:
    vector<int> nse(vector<int>&arr, int& n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(i);
                ans[i] = n;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
                ans[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> pse(vector<int>&arr, int& n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(i);
                ans[i] = -1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
                ans[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
        return ans;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>ans(n+1);
        vector<int>one = nse(arr, n);
        vector<int>two = pse(arr, n); 
        for(int i=0; i<n; i++){
            int len = one[i]-two[i]-1;
            ans[len] = max(ans[len], arr[i]);
        }
        if(ans[n-1]==0) ans[n-1] = *min_element(arr.begin(), arr.end());
        for(int i=n-1; i>=1; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};
