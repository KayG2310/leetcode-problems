class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int i) {
        if (i == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[i];
        if (ch == '.') {
            for (auto& [_, child] : node->children) {
                if (dfs(child, word, i + 1)) return true;
            }
            return false;
        } else {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            return dfs(node->children[ch], word, i + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
