// brute force --> tc = n*m 
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<char, char>forward;
        forward['z'] = 'a';
        for(char i='a'; i<'z'; i++){
            forward[i] = i+1;
        }
        unordered_map<char, char>backward;
        backward['a'] = 'z';
        for(char i='b'; i<='z'; i++){
            backward[i] = i-1;
        }
        unordered_map<int, int>indices;
        for(auto &it:shifts){
            int start = it[0];
            int end = it[1];
            int d = it[2];
            for(int i=start; i<=end; i++){
                if(d==1){
                    s[i] = forward[s[i]];
                }
                else{
                    s[i] = backward[s[i]];
                }
            }
        }
        return s;
    }
};

// optimal approach O(n) 
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>shift(n, 0);
        for(auto it: shifts){
            if(it[2]){
                // direction is positive 
                shift[it[0]]++;
                if(it[1]+1<n){
                    shift[it[1]+1]--;
                }
            }
            else{
                shift[it[0]]--;
                if(it[1]+1<n){
                    shift[it[1]+1]++;
                }
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += shift[i];
            shift[i] = sum;
        }
        // prefix sum is created
        for(int i=0; i<n; i++){
            int rotate;
            if(shift[i]>=0){
                rotate = shift[i]%26;
            }
            else{
                rotate = (shift[i] % 26 + 26) % 26;
            }
            s[i] = (s[i]-'a'+rotate)%26+'a';
            cout<<rotate<<endl;

        }
        return s;
    }
};
