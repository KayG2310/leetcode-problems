class Solution {
private:
    int gcd(int a, int b){
        if(b>a) return gcd(b, a);
        if(a%b==0) return b;
        return gcd(b, a%b);
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> freq;
        freq[nums[0]/pow(10,floor(log10(nums[0])))]++;
        for(int i=1; i<n; i++){
            int y = nums[i]%10;
            for(int j=1; j<10; j++){
                if(freq.find(j) != freq.end() && gcd(y,j)==1) cnt+= freq[j];
            }
            freq[nums[i]/pow(10,floor(log10(nums[i])))]++;
        } 
        return cnt;
    }
};
