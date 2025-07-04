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
    void inorder(TreeNode* root, int depth, int& maxdepth, int& sum){
        if(root == NULL) return;
        inorder(root->left, depth+1, maxdepth, sum);
        if(depth>maxdepth){
            maxdepth = depth;
            sum = root->val;
        }
        else if(depth == maxdepth){
            sum += root->val;
        }
        inorder(root->right, depth+1, maxdepth, sum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxdepth = 0, sum = 0;
        inorder(root, 0, maxdepth, sum);
        return sum;
    }
};
