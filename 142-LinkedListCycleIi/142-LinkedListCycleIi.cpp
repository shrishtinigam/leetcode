// Last updated: 8/30/2025, 8:19:52 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        int flag = 0;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *slow2 = head;
                while(slow != slow2){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            } 
        }
        return NULL;
    }
};