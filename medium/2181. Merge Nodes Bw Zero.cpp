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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* iter = head->next;
        int sum = 0;
        while(iter){
            while(iter != NULL && iter->val != 0){
                sum += iter->val;
                iter = iter->next;
            }
            if(sum){
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            sum = 0;
            iter = iter->next;
        }
        return dummy->next;
    }
};
