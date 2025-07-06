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
    bool leaf(TreeNode* root){
        if(!root->left && !root->right) return true;
        return false;
    }
    void f(TreeNode* root, int target, vector<vector<int>>&paths, vector<int>&temp, int sum){
        if(leaf(root)){
            if(sum+root->val  == target){
                temp.push_back(root->val);
                paths.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        if(root->left){
            f(root->left, target, paths, temp, sum+root->val);
        }
        if(root->right){
            f(root->right, target, paths, temp, sum+root->val);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == NULL) return {};
        if(leaf(root)){
            if(root->val == target) return {{root->val}};
            else return {};
        }
        vector<vector<int>>paths;
        vector<int>temp;
        temp.push_back(root->val);
        if(root->left)f(root->left, target, paths, temp, root->val);
        if(root->right)f(root->right, target, paths, temp, root->val);
        return paths;
    }
};
