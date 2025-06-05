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
    int inorder(TreeNode* root, int& cnt){
        if(root == NULL){
            return 0;
        }
        if(root->left && root->left->left==NULL && root->left->right==NULL){
            cnt = cnt + root->left->val;
        }
        inorder(root->left, cnt);
        inorder(root->right, cnt);
        return cnt; 
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int cnt = 0;
        return inorder(root, cnt);
    }
};
