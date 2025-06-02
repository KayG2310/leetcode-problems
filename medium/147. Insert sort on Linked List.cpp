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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        if (!head || !head->next) return head;
        dummy->next = head;
        ListNode* temp = head->next;
        head->next = NULL;
        while(temp){
            ListNode* next = temp->next;  
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < temp->val) {
                prev = prev->next;
            }
            temp->next = prev->next;
            prev->next = temp;
            temp = next;
        }

        return dummy->next;
    }
};
