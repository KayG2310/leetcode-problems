class Solution {
public:
    bool checkIfGood(int currMask, int prevMask, vector<vector<char>>& seats, int curr, int n){
        int prevBit = 0;
        for(int i=0;i<n;i++){
            bool set = ((1<<i)&currMask);
            if(!set){
                prevBit = 0;
                continue;
            }
            if(seats[curr][i]=='#' || prevBit){
                return false;
            }
            if(i>0 && (((1<<(i-1))&prevMask) || ((1<<(i+1))&prevMask))){
                return false;
            }
            else if((1<<(i+1))&prevMask){
                return false;
            }
            prevBit = 1;
        }
        return true;
    }
    int countBits(int n) {
        int cnt = 0;
        for(int i=0;i<10;i++) {
            if((n>>i)&1) cnt++;
        }
        return cnt;
    }
    int dp[10][257];
    int recurse(int currRow, int prevMask, vector<vector<char>>& seats, int n){
        if(currRow >= seats.size()){
            return 0;
        }
        if(dp[currRow][prevMask]!=-1){
            return dp[currRow][prevMask];
        }
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            int currMask = i;
            if(checkIfGood(currMask, prevMask, seats, currRow, n)){
                ans = max(ans, countBits(currMask) + recurse(currRow+1, currMask, seats, n));
            }
        }

        return dp[currRow][prevMask] = ans;
    }
    int maxStudents(vector<vector<char>>& seats) {

        memset(dp,-1,sizeof(dp));

        int n = seats[0].size();
        int ans = recurse(0,0,seats,n);

        return ans;
    }
};
