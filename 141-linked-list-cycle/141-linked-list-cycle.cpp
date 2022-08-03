/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time Complexity : O(N)
// Space Complexity : O(1)

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

/*
bool hasCycle(ListNode *head) {
	
        if(head == NULL)
            return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        
        return false;
    }
*/