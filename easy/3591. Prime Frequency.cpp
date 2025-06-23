class Solution {
private:
    void f(vector<int>& primes) {
        fill(primes.begin(), primes.end(), 1);
        primes[0] = primes[1] = 0;
        for(int i = 2; i * i < 121; ++i) {
            if(primes[i]) {
                for(int j = i * i; j < 121; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int>primes(121, -1);
        cout<<nums.size();
        f(primes);
        unordered_map<int, int>mpp;
        for(int i: nums) mpp[i]++;
        for(auto it: mpp){
            if(primes[it.second]==1) return true;
        }
        return false;
    }
};
