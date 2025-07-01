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
    void inorder(TreeNode* root, vector<int>&res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    TreeNode* build(vector<int>&res, int n, int l){
        if(n<l) return NULL;
        TreeNode* root = new TreeNode(res[(l+n)/2]);
        root->left = build(res, (l+n)/2 -1, l);
        root->right = build(res, n, (l+n)/2+1);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        inorder(root, res);
        // now make it balanced 

        return build(res, res.size()-1, 0);
    }
};
