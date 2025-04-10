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
    bool i(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        bool l = i(root->left, min, root->val);
        bool r = i(root->right, root->val, max);
        return l&&r;
    }
    bool isValidBST(TreeNode* root) {
        return i(root, LLONG_MIN, LLONG_MAX);
    }
};
