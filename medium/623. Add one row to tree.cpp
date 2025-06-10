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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return root;
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        // we have a good depth 
        int x = depth-1;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        while(!q.empty()){
            auto it = q.front();
            if(it.second == x) break;
            q.pop();
            if(it.first->left) q.push({it.first->left, it.second+1});
            if(it.first->right) q.push({it.first->right, it.second+1});
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* lefttree = it.first->left;
            TreeNode* righttree = it.first->right;
            TreeNode* newleft = new TreeNode(val);
            TreeNode* newright = new TreeNode(val);
            it.first->left = newleft;
            it.first->right = newright;
            newleft->left = lefttree;
            newright->right = righttree;
        }
        return root;
    }
};
