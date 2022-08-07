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
    }
};

/*
        ListNode * ptr = head;          
        ListNode * ptr2 = head;
        n++;
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
*/