class TrieNode {
public:
    TrieNode* children[27];
    int frequency;
    string sentence;
    TrieNode() {
        for (int i = 0; i < 27; i++) {
            children[i] = nullptr;
        }
        frequency = 0;
        sentence = "";
    }
    void insert(const string& sentence, int times) {
        TrieNode* currentNode = this;
        for (char ch : sentence) {
            int index = (ch == ' ') ? 26 : (ch - 'a');
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->frequency += times;
        currentNode->sentence = sentence;
    }
    TrieNode* search(const string& prefix) {
        TrieNode* currentNode = this;
        for (char ch : prefix) {
            int index = (ch == ' ') ? 26 : (ch - 'a');
            if (currentNode->children[index] == nullptr) {
                return nullptr;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode;
    }
};

class AutocompleteSystem {
private:
    TrieNode* trieRoot;
    string currentInput;
    struct TrieNodeComparator {
        bool operator()(TrieNode* a, TrieNode* b) {
            if (a->frequency == b->frequency) {
                return a->sentence > b->sentence;  
            }
            return a->frequency < b->frequency; 
        }
    };
    void dfs(TrieNode* node, priority_queue<TrieNode*, vector<TrieNode*>, TrieNodeComparator>& pq) {
        if (node == nullptr) return;
        if (node->frequency > 0) {
            pq.push(node);
            if (pq.size() > 3) pq.pop();
        }
        for (int i = 0; i < 27; i++) {
            dfs(node->children[i], pq);
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trieRoot = new TrieNode();
        currentInput = "";
        for (int i = 0; i < sentences.size(); i++) trieRoot->insert(sentences[i], times[i]);
    }
    vector<string> input(char c) {
        vector<string> suggestions;
        if (c == '#') {
            trieRoot->insert(currentInput, 1);
            currentInput = "";
            return suggestions;
        }
        currentInput += c;
        TrieNode* prefixNode = trieRoot->search(currentInput);
        if (prefixNode == nullptr) return suggestions;
        priority_queue<TrieNode*, vector<TrieNode*>, TrieNodeComparator> pq;
        dfs(prefixNode, pq);
        while (!pq.empty()) {
            suggestions.insert(suggestions.begin(), pq.top()->sentence);
            pq.pop();
        }
        return suggestions;
    }
};
