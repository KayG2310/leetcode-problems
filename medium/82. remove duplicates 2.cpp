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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev=dummy; ListNode* node = head;
        while(node != nullptr && node->next != NULL){
            int cnt = 0;
            while(node != nullptr && node->next != NULL && node->val == node->next->val){
                node = node->next;
                cnt++;
            }
            if(cnt==0){
                prev = node;
                node = node->next;
            }
            else{
                prev->next = node->next; 
                node = node->next;
            }
        }
        return dummy->next;
    }
};
