struct Node{
    Node* next;
    Node* prev;
    string s;
    Node(string k){
        next = nullptr;
        prev = nullptr;
        s = k;
    }
};

class BrowserHistory {
public:
    Node* head; Node* temp;
    BrowserHistory(string homepage) {
        head= new Node(homepage);
        temp = head;
    }
    
    void visit(string url) {
        temp->next = new Node(url);
        temp->next->prev = temp;
        temp = temp->next;
    }
    
    string back(int steps) {
        if(temp == NULL) return "";
        Node* cur = temp;
        cur = temp;
        while(cur && cur->prev && steps){
            steps--;
            cur = cur->prev;
        }
        temp = cur;
        return cur->s;
    }
    string forward(int steps) {
        if(temp == NULL) return "";
        Node* cur = temp;
        cur = temp;
        while(cur && cur->next && steps){
            steps--;
            cur = cur->next;
        }
        temp = cur;
        return cur->s;
    }
};
