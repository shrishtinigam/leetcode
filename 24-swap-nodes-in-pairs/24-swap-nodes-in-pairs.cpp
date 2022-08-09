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
    /* Recursive Solution
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
    */
    
    /* Iterative Solution */
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head) 
            return head;
        ListNode* newHead = new ListNode(-1);
        ListNode* prev = newHead;
        ListNode* cur = head;
        while (cur)
        {
            if (!cur->next) 
            {
                prev->next = cur;
                cur = cur->next;
            }
            else
            {
                ListNode* temp = cur->next->next;
                prev->next = cur->next; 
                prev = prev->next;
                prev->next = cur; 
                prev = prev->next;
                prev->next = NULL;
                cur = temp;
            }
        }
        return newHead->next;
    }

};