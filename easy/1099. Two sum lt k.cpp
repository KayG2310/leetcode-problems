class Solution {
  public:
    pair<int, int> maxSum(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        pair<int, int>ans = {-1, -1}; 
        int i= 0, j = n-1;
        while(i<j){
            if(arr[i]+arr[j] < k){
                if(ans.first == -1) ans = {arr[i], arr[j]};
                else{
                    if(arr[i]+arr[j] > ans.first+ans.second){
                        ans = {arr[i], arr[j]};
                    }
                    else if(arr[i]+arr[j] == ans.first+ans.second && (arr[j]-arr[i]) > (ans.second - ans.first)){
                        ans = {arr[i], arr[j]};
                    }
                }
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
