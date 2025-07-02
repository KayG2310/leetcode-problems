/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isleaf(TreeNode* root){
        if(root == NULL) return true;
        if(!root->left && !root->right) return true;
        return false;
    }
    void p(TreeNode* root, map<TreeNode*, TreeNode*>&parent, vector<TreeNode*>&leaves){
        if(root == NULL) return;
        if(isleaf(root)) {
            leaves.push_back(root);
            return; 
        }
        if(root->left){
            parent[root->left] = root;
            p(root->left, parent, leaves);
        } 
        if(root->right){
            parent[root->right] = root;
            p(root->right, parent, leaves);
        }
    }
    void countt(int distance, map<TreeNode*, TreeNode*>&parent, int& cnt, int d, TreeNode* cur, TreeNode* leaf){
        if(cur == NULL) return; 
        if(isleaf(cur) && d<=distance){
            cnt++;
            return;
        }
        if(cur->left != leaf && 1+d<=distance){
            // other child 
            countt(distance, parent, cnt, 1+d, cur->left, cur);
        }
        if(cur->right != leaf && 1+d<=distance){
            // other child 
            countt(distance, parent, cnt, 1+d, cur->right, cur);
        }
        if(parent[cur] != leaf && parent[cur] != NULL && 1+d<=distance){
            // other child 
            countt(distance, parent, cnt, 1+d, parent[cur], cur);
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        if(root == NULL || isleaf(root)) return 0;
        map<TreeNode*, TreeNode*>parent;
        vector<TreeNode*>leaves;
        parent[root] = NULL;
        p(root, parent, leaves);
        // we have parents, we have leaf
        int cnt = 0;
        for(auto it: leaves){
            countt(distance, parent, cnt, 1, parent[it], it);
        }
        // for(auto it: leaves){
        //     cout<<it->val<<endl;
        // }
        return cnt/2;
    }
};
