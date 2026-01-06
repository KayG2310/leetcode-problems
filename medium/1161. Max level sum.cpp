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
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans_level = 0, curlevel = 0; 
        long long sum = LLONG_MIN; 
        queue<TreeNode*>q; 
        q.push(root); 
        while(!q.empty()){
            int n = q.size();
            long long cursum = 0; 
            for(int i=0; i<n; i++){
                cursum += q.front()->val; 
                if(q.front()->left) q.push(q.front()->left); 
                if(q.front()->right) q.push(q.front()->right); 
                q.pop();
            }
            curlevel++; 
            if(cursum > sum){
                sum = cursum;
                ans_level = curlevel;
            }
        }
        return ans_level;
    }
};
