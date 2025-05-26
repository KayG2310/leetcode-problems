class Solution {
private:
    bool f(TreeNode* root, int sum, int target){
        if(!root->left && !root->right && sum+root->val == target) return true;
        bool x=false, y=false;
        if(root->left){
            x = f(root->left, sum+root->val, target);
        }
        if(root->right){
            y = f(root->right, sum+root->val, target);
        }
        return x||y;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return f(root, 0, targetSum);
    }
};
