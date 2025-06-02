class Solution {
public:
    Node* connect(Node* root) {
        // not height balanced 
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
