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
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1); 
        ListNode* d = dummy;
        // traversal 1 to store elements in a vector 
        vector<ListNode*>els; 
        ListNode* temp = head;
        while(temp){
            els.push_back(temp);
            temp = temp->next;
        }
        // make nge 
        int n = els.size();
        stack<ListNode*>st;
        st.push(els[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top()->val<=els[i]->val) st.pop();
            if(!st.empty()){
                st.push(els[i]);
                els[i] = NULL;
            }
            else{
                st.push(els[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(els[i]){
                d->next = els[i];
                d = d->next;
            }
        }
        return dummy->next;
    }
};
