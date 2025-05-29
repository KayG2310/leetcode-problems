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
private:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        if(head == NULL || head->next == NULL || left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* l=dummy; ListNode* r=dummy;

        while(true){
            if(cnt == left-1){
                break;
            }
            l = l->next;
            cnt++;
        }
        
        cnt = 0;
        while(true){
            if(cnt == right-1){
                break;
            }
            r = r->next;
            cnt++;
        }
        // l is 1
        ListNode* temp1 = r->next->next;
        ListNode* temp2 = l->next;
        r->next->next = NULL;
        ListNode* newhead = reverse(l->next);
        l->next = newhead; 
        temp2->next = temp1;
        return dummy->next;
    }
};
