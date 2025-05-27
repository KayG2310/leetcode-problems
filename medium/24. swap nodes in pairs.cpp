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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        head = temp->next;
        ListNode* temp2 = head->next;
        head->next = temp;
        temp->next = temp2;
        ListNode*prev = temp;
        temp= temp->next;
        while(temp != NULL && temp->next != NULL){
            ListNode* node = temp->next->next;
            ListNode* node2 = temp->next;
            prev->next = node2;
            node2->next = temp;
            temp->next = node;
            prev = temp;
            temp = temp->next;
        }
        return head;
        
    }
};
