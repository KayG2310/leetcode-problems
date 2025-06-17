/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        map<Node*, Node*>mpp;
        queue<Node*>q;
        set<Node*>vis;
        vis.insert(node);
        q.push(node);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            mpp[it] = new Node(it->val);
            for(auto i: it->neighbors){
                if(vis.find(i) == vis.end()){
                    vis.insert(i);
                    q.push(i);
                }
            }
        }
        for(auto it: mpp){
            Node* temp = it.second;
            for(auto i: it.first->neighbors){
                temp->neighbors.push_back(mpp[i]);
            }
        }
        return mpp[node];
    }
};
