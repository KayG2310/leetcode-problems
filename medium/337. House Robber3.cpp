// recursive code 
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
    int f(TreeNode* root, int canrob){
        if(root==NULL) return 0;
        int ans = 0;
        if(canrob==0){
            ans = max(ans, f(root->left, !canrob)+f(root->right, !canrob));
        }
        else{
            ans = max(ans, max(root->val+f(root->left, !canrob)+f(root->right, !canrob), f(root->left, canrob)+f(root->right, canrob)));
        }
        return ans;
    }
public:
    int rob(TreeNode* root) {
        return f(root, 1);
    }
};


// optimise unique optimisation 
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
    int f(TreeNode* root, int canrob, map<pair<TreeNode*, int>, int>&dp){
        if(root==NULL) return 0;
        if(dp.find({root, canrob}) != dp.end()) return dp[{root, canrob}];
        int ans = 0;
        if(canrob==0){
            ans = max(ans, f(root->left, !canrob, dp)+f(root->right, !canrob, dp));
        }
        else{
            ans = max(ans, max(root->val+f(root->left, !canrob, dp)+f(root->right, !canrob, dp), f(root->left, canrob, dp)+f(root->right, canrob, dp)));
        }
        return dp[{root, canrob}] = ans;
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*, int>, int>dp;
        return f(root, 1, dp);
    }
};
