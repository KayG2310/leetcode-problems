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
    void inorder(TreeNode* root, int &sum){
        if(root == NULL){
            return;
        }
        inorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        inorder(root->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return root; 
    }
};
/*
sum = 36
minisum = 0, sum-minisum+0 = 36 
ms = 1, sum-1+1 = 26 
ms = 3, 36-3+2 = 35
ms = 6, 36-6+3 = 33 
*/ 
