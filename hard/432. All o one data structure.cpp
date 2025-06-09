struct Node{
    Node* next;
    Node* prev;
    int freq;
    unordered_set<string>words;

    Node(int i, string s){
        freq = i;
        words.insert(s);
    }
    Node(){
        next = NULL;
        prev = NULL;
        freq = -1;
    }
};
class AllOne {
unordered_map<string, int>mpp1;
map<int, Node*>mpp2;
Node* dummy_head;
Node* dummy_tail;
public:
    AllOne() {
        dummy_head = new Node();
    dummy_tail = new Node();
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
    }
    
    void inc(string key) {
        if(mpp1.find(key)==mpp1.end()){
            // 1st appearance of string 
            int f = 1;
            mpp1[key]++;
            if(mpp2.find(f) == mpp2.end()){
                // freq does not exist
                Node* node = new Node(f, key);
                Node* temp = dummy_head;
                while(temp != NULL && temp->next != NULL && temp->next->freq < f && temp->next != dummy_tail) temp=temp->next;
                Node* nn = temp->next;
                temp->next = node;
                node->next = nn;
                node->prev = temp;
                nn->prev = node;
                mpp2[f] = node;
            }
            else{
                // freq exists
                Node* cur = mpp2[f];
                cur->words.insert(key);
            }
        }
        else{
            // if the word exists already --> list also exists
            int curf = mpp1[key]; 
            mpp1[key]++;
            Node* cur = mpp2[curf];
            cur->words.erase(key);
            if(cur->words.empty()){
                Node* p = cur->prev;
                Node* n = cur->next;
                p->next = n;
                n->prev = p;
                mpp2.erase(curf);     // remove from map
                delete cur;           // free memory
            }
            curf++; 
            if(mpp2.find(curf) == mpp2.end()){
                // freq does not exist
                Node* node = new Node(curf, key);
                Node* temp = dummy_head;
                while(temp != NULL && temp->next != NULL && temp->next->freq < curf && temp->next != dummy_tail) temp=temp->next;
                Node* nn = temp->next;
                temp->next = node;
                node->next = nn;
                node->prev = temp;
                nn->prev = node;
                mpp2[curf] = node;
            }
            else{
                // freq exists
                mpp2[curf]->words.insert(key);
            }
        }
    }
    
    void dec(string key) {
        // if the word exists already --> list also exists
        int curf = mpp1[key]; 
        mpp1[key]--;
        if(mpp1[key]==0) mpp1.erase(key);
        Node* cur = mpp2[curf];
        cur->words.erase(key);
        if(cur->words.empty()){
            Node* p = cur->prev;
            Node* n = cur->next;
            p->next = n;
            n->prev = p;
            mpp2.erase(curf);     // remove from map
            delete cur;           // free memory
        }
        curf--; 
        if(curf==0) return;
        if(mpp2.find(curf) == mpp2.end()){
            // freq does not exist
            Node* node = new Node(curf, key);
            Node* temp = dummy_head;
            while(temp != NULL && temp->next != NULL && temp->next->freq < curf && temp->next != dummy_tail) temp=temp->next;
            Node* nn = temp->next;
            temp->next = node;
            node->next = nn;
            node->prev = temp;
            nn->prev = node;
            mpp2[curf] = node;
        }
        else{
            // freq exists
            mpp2[curf]->words.insert(key);
        }
    }
    
    string getMaxKey() {
        auto it = mpp2.rbegin();
        if(it != mpp2.rend()) return *(it->second->words.begin());
        return "";
    }
    
    string getMinKey() {
        auto it = mpp2.begin();
        if(it != mpp2.end()) return *(it->second->words.begin());
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
