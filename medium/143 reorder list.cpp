/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 1 2 3 4 5 
 1 5      2 4.   3 
 1 2 3.    4 5 reverse the second half 
 1 2 3.    5 4 
 head1, head2, go on recombining

 1 2 3 4 5 6 
 16   25.  34 
 1 2 3.   6 5 4 
 */
class Solution {
private:
    ListNode* middle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        /*
         1 2 3 4 5 
        */
    }

    ListNode* reverse(ListNode* root){
        if(root == NULL || root->next == NULL){
            return root;
        }
        ListNode* newhead = reverse(root->next);
        ListNode* front = root->next;
        front->next = root;
        root->next = NULL;
        return newhead;
    }
public:
    void reorderList(ListNode* head) {
        // step 1 : find the middle node
        if(head == NULL || head->next == NULL) return;
        ListNode* mid = middle(head);
        ListNode* secHalf = mid->next;
        mid->next = NULL;
        cout<<"middle node: "<<mid->val<<endl;

        // step 2 : reverse the second half
        
        ListNode* head2 = reverse(secHalf);
        cout<<"reverse node: "<<head2->val<<endl;

        // step 3 : combining both
        ListNode* head1 = head;
        
        while(head2 != NULL){
            ListNode* front1 = head1->next;
            ListNode* front2 = head2->next;
            head1->next = head2;
            head1->next->next = front1;

            head1 = front1;
            head2 = front2;
/*
1 2 3.         5 4 
front1 = 3, front2 = null
1->5->2->4->3 h1 = 3, head2 = null
*/
        }
    }
};
