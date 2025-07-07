class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans; 
        for(auto it: queries){
            int a = it[0];
            int b = it[1];
            int steps = 0;
            while(a != b){
                while(a>b){
                    a = a/2;
                    steps++;
                }
                while(b>a){
                    b = b/2;
                    steps++;
                }
            }
            steps += 1;
            ans.push_back(steps);
        }
        return ans;
    }
};
/*
        1 
    2       3 
4      5  6     7
*/
