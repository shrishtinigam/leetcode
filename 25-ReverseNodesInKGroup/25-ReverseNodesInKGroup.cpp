// Last updated: 8/30/2025, 8:21:12 PM
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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        int k1 = k;
        while(true){
            // Get Kth 
            ListNode * kth = groupPrev;
            k1 = k;
            while(kth and k1 > 0){
                kth = kth->next;
                k1--;
            }
            if(!kth)
                break;
            ListNode *groupNext = kth->next;
            ListNode *prev = kth->next, *curr = groupPrev->next;
            while(curr != groupNext){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode *temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
};