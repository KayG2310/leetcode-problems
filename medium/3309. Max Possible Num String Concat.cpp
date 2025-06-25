class Solution {
private:
    int f(string s){
        int num = 0, p = 0;
        int n = s.length();
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                num += pow(2, p);
            }
            p++;
        }
        return num;
    }
    string f2(int num){
        string s = "";
        int j=7;
        while(j>=0 && (num&(1<<j))==0) j--;
        for(int i=j; i>=0; i--){
            if(num&(1<<i)) s+='1';
            else s += '0';
        }
        return s;
    }
public:
    int maxGoodNumber(vector<int>& nums) {
        // 0 1 2
        int ans = 0;
        ans = max(ans, f(f2(nums[0])+f2(nums[1])+f2(nums[2])));
        // 0 2 1
        ans = max(ans, f(f2(nums[0])+f2(nums[2])+f2(nums[1])));
        // 1 0 2
        ans = max(ans, f(f2(nums[1])+f2(nums[0])+f2(nums[2])));
        // 1 2 0 
        ans = max(ans, f(f2(nums[1])+f2(nums[2])+f2(nums[0])));
        // 2 0 1
        ans = max(ans, f(f2(nums[2])+f2(nums[0])+f2(nums[1])));
        ans = max(ans, f(f2(nums[2])+f2(nums[1])+f2(nums[0])));
        return ans;
    }
};
