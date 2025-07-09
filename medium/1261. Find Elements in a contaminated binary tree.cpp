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
class FindElements {
public:
    unordered_map<int, int>mpp;
    FindElements(TreeNode* root) {
        // recover and put nodes in a set
        if(root != NULL) root->val = 0;
        inorder(root, mpp);

        
    }
    void inorder(TreeNode* root, unordered_map<int, int>&mpp){
        if(root == NULL) return; 
        if(root->left){
            root->left->val = 2*(root->val)+1;
            inorder(root->left, mpp);
        }
        mpp[root->val]++;
        if(root->right){
            root->right->val = 2*(root->val)+2;
            inorder(root->right, mpp);
        }
    }
    bool find(int target) {
        return mpp[target]>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
