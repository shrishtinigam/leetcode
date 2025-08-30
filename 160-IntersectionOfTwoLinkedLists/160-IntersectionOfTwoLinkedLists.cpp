// Last updated: 8/30/2025, 8:19:42 PM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        while(tempA != tempB){
            if(tempA)
                tempA = tempA->next;
            else
                tempA = headB;
            
            if(tempB)
                tempB = tempB->next;
            else
                tempB = headA;
        }
        return tempA;
    }
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na = 0, nb = 0;
        ListNode *tempA = headA, *tempB = headB;
        while(tempA){
            tempA = tempA->next;
            na++;
        }
        while(tempB){
            tempB = tempB->next;
            nb++;
        }
        tempA = headA;
        tempB = headB;
        if(na > nb){
            int diff = na - nb;
            while(diff--){
                tempA = tempA->next;
            }
        }
        if(nb > na){
            int diff = nb - na;
            while(diff--){
                tempB = tempB->next;
            }
        }

        while(tempA){
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
    */
};