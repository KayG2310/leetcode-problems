class Solution {
private:
    TreeNode* check(TreeNode* n){
        if(n == NULL) return n;
        TreeNode* temp = n->left;
        n->left = check(n->right);
        n->right = check(temp);
        return n;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return check(root);
    }
};
