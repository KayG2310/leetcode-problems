// brute force kind of 
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string>words;
        vector<int>spaces;
        int i = 0; 
        while(i<s.length()){
            int spacecount = 0;
            while(s[i]==' ' && i<s.length()){
                spacecount++;
                i++;
            }
            spaces.push_back(spacecount);
            string word = "";
            while(s[i]!=' ' && i<s.length()){
                word += s[i];
                i++;
            }
            words.push_back(word);
        }
        for(int c : spaces){
            cout<<c<<"-->";
        }
        cout<<endl;
        for(string k:words){
            cout<<k<<"--->";
        }
        cout<<endl;
        int in=0;
        for(int &val: spaces){
            for(int i=0; i<val; i++){
                ans += ' ';
            }
            if(in < words.size()){
                for(int i = words[in].length()-1; i>=0; i--){
                    ans += words[in][i];
                }
                in++;
            }
        }
        return ans;
    }
};


// optimal --> using 2 pointer approach 
class Solution {
public:
    string reverseWords(string s) {
        string ans = s;
        int n = s.length();
        int i=0, j= 0;
        while(i<n && j<n){
            while(ans[i] == ' ' && i<n){
                i++;
            }
            j = i;
            while(ans[j] != ' ' && j<n){
                j++;
            }
            j--;
            int copy1 = i, copy2 = j;
            while(copy1<= copy2){
                swap(ans[copy1], ans[copy2]);
                copy1++;
                copy2--;
            }
            i = j+1;
        }
        
        return ans;
    }
};
