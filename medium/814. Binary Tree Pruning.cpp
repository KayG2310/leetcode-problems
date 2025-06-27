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
    TreeNode* prune(TreeNode* root){
        if(root == NULL) return root;
        root->left = prune(root->left);
        root->right = prune(root->right);
        if(root->val != 1 && !root->left && root->right == NULL) return NULL;
        return root;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root);
    }
};
