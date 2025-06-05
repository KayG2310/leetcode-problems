/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* trav(TreeNode* root1, TreeNode* root2, TreeNode* target){
        if(root1 == NULL || root2 == NULL) return NULL; 
        if(root1 == target) return root2;
        TreeNode* left = trav(root1->left, root2->left, target);
        if (left) return left;

        return trav(root1->right, root2->right, target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return trav(original, cloned, target);
    }
};
