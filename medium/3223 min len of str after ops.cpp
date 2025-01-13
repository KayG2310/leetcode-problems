class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        int cnt = 0;
        for(auto it: mpp){
            if(it.second < 3) cnt += it.second;
            else{
                if(it.second%2) cnt++;
                else cnt +=2;
            }
        }
        return cnt;
    }
};
