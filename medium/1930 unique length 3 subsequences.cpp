class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>unique;
        unordered_set<char>palindrome;
        int number = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            unique.insert(s[i]);
        }
        for(auto it:unique){
            // we will treat it as xyx as x
            int start_index = -1;
            int end_index = 0;
            for(int i=0; i<n; i++){
                if(s[i]==it){
                    if(start_index == -1) start_index = i;
                    else end_index = i;
                }
            }
            // cant take int cnt here as we may end up with duplicates
            
            for(int i = start_index+1; i <= end_index-1; i++){
                palindrome.insert(s[i]);
            }
            number += palindrome.size();
            palindrome.clear();
        }
        return number;
    }
};
