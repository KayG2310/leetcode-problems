// brute force 
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        unordered_map<char, char>mpp;
        for(int i=0; i<25; i++){
            mpp['a'+i] = 'a'+(i+1);
        }
        mpp['z'] = 'a';
        string s = "a";
        for(int i: operations){
            if(i){
                string m = "";
                for(char c: s) m += mpp[c];
                s = s+m;
            }
            if(!i){
                s = s+s;
            }
            if(s.length()>=k) return s[k-1];
        }
        return s[k-1];
    }
};

// optimal 
