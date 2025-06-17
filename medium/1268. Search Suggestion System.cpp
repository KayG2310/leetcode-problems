struct Node{
    Node* links[26];
    bool flag = false;
    bool contains(char c){
        return links[c-'a'] != NULL;
    }
    void put(char c, Node* node){
        links[c-'a'] = node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setend(){
        flag = true;
    }
};

class Trie{
    public:
    Node* root; 
    Trie(){
        root = new Node();
    }
    void putword(string s){
        Node* node = root; 
        for(int i=0; i<s.length(); i++){
            if(node->contains(s[i])==0){
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setend();
    }
    Node* match(string s){
        Node* node = root;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(node->contains(s[i])==false) return NULL;
            node = node->get(s[i]);
        }
        return node;
    }
};
class Solution {
private:
    void dfs(string s, vector<string>&temp, Node* ending){
        if(ending->flag == true && temp.size()<3){
            temp.push_back(s);
            // ✅ don't return — we might still find more suggestions
        }
        if(temp.size()==3) return;
        for(int i=0; i<26; i++){
            if(ending->contains('a'+i)){
                char x = 'a'+i;
                dfs(s+x, temp, ending->get(x));
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string word) {
        int n = p.size();
        int m = word.length();
        sort(p.begin(), p.end());
        Trie trie; 
        for(string s: p){
            trie.putword(s);
        }
        vector<vector<string>>ans;
        string s = "";
        for (char c : word) {
            s += c;
            Node* ending = trie.match(s);
            vector<string> temp;
            if (ending != NULL) {
                dfs(s, temp, ending);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
