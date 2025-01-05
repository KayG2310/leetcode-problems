class Solution {
public:
    bool isPalindrome(string s) {
        string copy = "";
        int n = s.length();
        for(int i=0; i<n; i++){
            if((s[i]-'a'>=0 && s[i]-'a'<26) || (s[i]-'A'>=0 && s[i]-'A'<26) || (s[i]-'0'>=0 && s[i]-'0'<10)){
                copy += tolower(s[i]);
            }
        }
        cout<<copy;
        int m = copy.length();
        int i=0, j= m-1;
        while(i<=j){
            if(copy[i] != copy[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
