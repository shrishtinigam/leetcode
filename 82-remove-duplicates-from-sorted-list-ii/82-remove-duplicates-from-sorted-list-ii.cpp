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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode * cur = head;
        ListNode * dummy = new ListNode(0, head);
        ListNode * last = dummy;
        ListNode * next;
        while(cur->next)
        {
            next = cur->next;
            
            if(next and cur->val != next->val){
                last = cur;
                cur->next = next;
                cur = cur->next;
                continue;
            }
                
            
            while(next and cur->val == next->val){
                next = next->next;
            }
            
            if(!next){
                last->next = next;
                return dummy->next;
            }
            
            last->next = next;
            cur = next;
        }
        
        last = cur;
        return dummy->next;
    }
};

/*
ListNode * cur = head;
        
        while(cur)
        {
            ListNode * next = cur->next;
            
            while(next and cur->val == next->val)
                next = next->next;
            
            cur->next = next;
            cur = cur->next;
        }
        
        return head;
*/