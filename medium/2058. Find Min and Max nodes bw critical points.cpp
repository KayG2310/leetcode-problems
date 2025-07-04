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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // base case handled 
        if(!head || !head->next || !head->next->next) return {-1,-1}; 
        int first = 1, prev = 1, mini = 1e9, maxi = 0, index = 2;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head->next->next; 
        int cnt = 0;
        while(p3){
            if(p2->val > p1->val && p2->val > p3->val){
                cnt++;
                if(first == 1) first = index;
                if(prev != 1) mini = min(mini, index-prev);
                prev = index; 
                maxi = index; 
            }
            else if(p2->val < p1->val && p2->val < p3->val){
                cnt++;
                if(first == 1) first = index;
                if(prev != 1) mini = min(mini, index-prev);
                prev = index; 
                maxi = index;
            }
            index++;
            p1 = p2;
            p2 = p3; 
            p3 = p3->next;
        }
        if(cnt<2) return {-1, -1};
        return {mini, maxi-first};
    }
};
