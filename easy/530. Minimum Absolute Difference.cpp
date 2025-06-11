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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int>ans;
        inorder(root, ans);
        int a = 1e9;
        for(int i=1; i<ans.size(); i++){
            a = min(a,abs(ans[i]-ans[i-1]));
        }
        return a;
    }
};
