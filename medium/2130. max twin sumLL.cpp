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
    ListNode* mid(ListNode* head){
        if(head==NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
public:
    int pairSum(ListNode* head) {
        if(head == NULL) return 0;
        if(head->next->next == NULL) return head->val+head->next->val;
        ListNode* m = mid(head);
        ListNode* m2 = m->next;
        m->next = NULL;
        ListNode* temp2 = reverse(m2);
        ListNode* temp1 = head;
        int ans = 0;
        while(temp2 && temp1){
            ans = max(ans, temp1->val+temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return ans;
    }
};
