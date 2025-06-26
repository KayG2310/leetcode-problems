class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>a(26);
        vector<int>b(26);
        for(char c:s) a[c-'a']++;
        for(char c:t) b[c-'a']++;
        for(int i=0; i<26; i++){
            if(a[i] != b[i]) return 'a'+i;
        }
        return 'z';
    }
};
