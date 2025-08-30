// Last updated: 8/30/2025, 8:20:41 PM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) 
            return head;
        
        int len = 1; 
        ListNode *newH = head, *tail = head;
        // get the number of nodes in the list
        while(tail->next){
            tail = tail->next;
            len++;
        }

        tail->next = head; // circle the link

        // the tail node is the (len-k)-th node (1st node is head)
        k %= len;
        for(auto i = 0; i < len - k; i++) 
            tail = tail->next; 
        
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};