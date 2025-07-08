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
    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp){
        if(root->left){
            mpp[root->left] = root;
            inorder(root->left, mpp);
        }
        if(root->right){
            mpp[root->right] = root;
            inorder(root->right, mpp);
        }
    }
    void inorder2(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp, int& cnt){
        if(root->left){
            mpp[root->left] = root;
            inorder2(root->left, mpp, cnt);
        }
        if(mpp[root] != NULL && mpp[mpp[root]]!= NULL && mpp[mpp[root]]->val%2==0){
            cnt += root->val;
        }
        if(root->right){
            mpp[root->right] = root;
            inorder2(root->right, mpp, cnt);
        }
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL || (!root->left && !root->right)) return 0;
        unordered_map<TreeNode*, TreeNode*>mpp; 
        mpp[root] = NULL;
        inorder(root, mpp);
        // parents are marked, call inorder again
        int cnt = 0;
        inorder2(root, mpp, cnt);
        return cnt;
    }
};

// more optimise? 
class Solution {
private:
    void inorder2(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp, int& cnt){
        if(root->left){
            mpp[root->left] = root;
            inorder2(root->left, mpp, cnt);
        }
        if(mpp[root] != NULL && mpp[mpp[root]]!= NULL && mpp[mpp[root]]->val%2==0){
            cnt += root->val;
        }
        if(root->right){
            mpp[root->right] = root;
            inorder2(root->right, mpp, cnt);
        }
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL || (!root->left && !root->right)) return 0;
        unordered_map<TreeNode*, TreeNode*>mpp; 
        mpp[root] = NULL;
        int cnt = 0;
        inorder2(root, mpp, cnt);
        return cnt;
    }
};
