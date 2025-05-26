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
    int f(TreeNode* root){
        if(root == NULL){
            return 1e8;
        }
        if(root->left == NULL && root->right == NULL) return 1;
        int lf = f(root->left);
        int rh = f(root->right);
        return 1+min(lf, rh);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return f(root);
    }
};
