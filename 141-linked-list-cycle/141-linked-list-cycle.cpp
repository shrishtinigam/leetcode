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
    bool hasCycle(ListNode *head) 
    {
        ListNode* tortoise = head, *hare = head;
        while(tortoise != NULL and hare != NULL){
            tortoise = tortoise->next;
            hare = hare->next;
            if(hare == NULL)
                return false;
            hare = hare->next;
            if(tortoise == hare)
                return true;
        }
        return false;
    }
};