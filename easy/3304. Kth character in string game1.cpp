class Solution {
public:
    char kthCharacter(int k) {
        unordered_map<char, char>mpp;
        for(int i=0; i<25; i++){
            mpp['a'+i] = 'a'+(i+1);
        }
        mpp['z'] = 'a';
        string s = "a";
        while(s.length()<k){
            string m = "";
            for(char c: s) m += mpp[c];
            s = s+m;
        }
        return s[k-1];
    }
};
