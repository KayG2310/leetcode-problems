// tc = O(n+n), sc = O(n)
class Solution {
private:
    
    TreeNode* build(int left, int right, vector<int>&arr){
        if(left>right){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(left, mid-1, arr);
        root->right = build(mid+1, right, arr);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        return build(0, n-1, arr);
    }
};

// optimal tc = O(n), sc = O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* midd(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        return prev;
    }
private:
    TreeNode* build(ListNode* head){
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prevMid = midd(head);
        ListNode* mid = nullptr;

        if (prevMid) {
            mid = prevMid->next;
            prevMid->next = nullptr; 
        }
        else{
            mid = head;
        head = nullptr;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = build(head);        
        root->right = build(mid->next);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
};
