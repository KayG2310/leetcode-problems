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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* t1 = dummy1;
        ListNode* t2 = dummy2;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                t1->next = temp;
                t1 = t1->next;
            }
            else{
                t2->next = temp;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        t2->next = NULL;
        t1->next = dummy2->next;
        return dummy1->next;
    }
};
