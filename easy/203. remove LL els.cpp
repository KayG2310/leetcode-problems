class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL || (head->next == NULL && head->val == val)) return NULL;
        if(head->next == NULL) return head;
        while(head != NULL && head->val == val){
            head = head->next;
        }
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;
    }
};
