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
    int dfs(TreeNode* root, int& moves) {
        if (!root) return 0;
        int left = dfs(root->left, moves);
        int right = dfs(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves); 
        return moves;  
    }
};
