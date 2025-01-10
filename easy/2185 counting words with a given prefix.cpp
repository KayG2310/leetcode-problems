class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i=0; i<words.size(); i++){
            bool flag = true;
            for(int j=0; j<pref.length(); j++){
                if(words[i][j] != pref[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
