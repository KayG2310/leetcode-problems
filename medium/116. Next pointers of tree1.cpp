/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int x = q.size();
            queue<Node*>q2;
            for(int i=0; i<x; i++){
                Node* temp = q.front();
                q.pop();
                q2.push(temp);
                if(!q.empty()){
                    temp->next = q.front();
                }
                else{
                    temp->next = NULL;
                }
            }
            while(!q2.empty()){
                Node* temp = q2.front();
                q2.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};

// optimal 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int x = q.size();
            for (int i = 0; i<x; i++) {
                auto front = q.front();
                q.pop();

                // last node
                if (i == x-1) {
                    front->next = nullptr;
                }
                // not last node
                else {
                    front->next = q.front();
                }

                // insert children if exists
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        return root;
    }
};
