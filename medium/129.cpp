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
    void preorder(TreeNode* root, int &temp, int &sum){
        if(root == NULL) return;
        temp = temp*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum+=temp;
            temp -= root->val;
            temp = temp/10;
            return;     
        }
         
        preorder(root->left, temp, sum);
        preorder(root->right, temp, sum);
        temp -= root->val;
        temp = temp/10;

    }
public:
    int sumNumbers(TreeNode* root) {
        int temp = 0, sum = 0;
        preorder(root, temp, sum);
        return sum;
    }
};
