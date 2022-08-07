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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Two pointer approach
        // Making sure the gap between the two pointers is n
        ListNode *fast = head, *slow = head;
        while(n--) 
            fast = fast -> next;      // iterate first n nodes using fast
        if(!fast) 
            return head -> next;       // if fast is already null, it means we have to delete head itself. 
                                       // So, just return next of head
        
        while(fast -> next)            // iterate till fast reaches the last node of list
            fast = fast -> next, slow = slow -> next;            
        
        slow -> next = slow -> next -> next; // remove the nth node from last
        return head;

    }
};

/*
        Two Pointer
        
        ListNode * ptr = head; // ahead pointer         
        ListNode * ptr2 = head; // behind pointer
        n++;
        // sending the ahead pointer forward by n steps
        while(n > 0 and ptr != NULL)
        {
            ptr = ptr->next;
            n--;
        }
        if(n == 1)
            return head->next;
        while(ptr != NULL)
        {
            ptr = ptr->next;            
            ptr2 = ptr2->next;
        }
        if(ptr2->next != NULL)
            ptr2->next = ptr2->next->next;
        else
            head = NULL;
        return head;
        
        
        
        
        
        Finding the length method
        
        if(head->next == NULL)
            return NULL;
        ListNode* ptr = head;
        int l = 0;
        while(ptr){
            ptr = ptr->next;
            l++;
        }
        ptr = head;
        if(l == n){
            return head->next;
        }
        l = l - n - 1;
        while(l--){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
*/