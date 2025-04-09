class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        map<int, char> mpp;
        for(int i = 1; i <= 26; i++){
            mpp[i] = 'A' + (i - 1);
        }

        while(columnNumber){
            columnNumber--;  // Key fix: shift to 0-based
            int x = columnNumber % 26;
            ans = mpp[x + 1] + ans;  // now x is in [0-25], so use mpp[x + 1]
            columnNumber /= 26;
        }
        return ans;
    }
};
