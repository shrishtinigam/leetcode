// Last updated: 8/30/2025, 8:21:30 PM
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


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode newHead(0);
        ListNode *t = &newHead;
        while(c || l1 || l2) {
            c += (l1? l1->val : 0) + (l2? l2->val : 0);
            t->next = new ListNode(c%10);
            t = t->next;
            c /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return newHead.next;
    }
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) 
            return NULL;
        int c = (l1? l1->val:0) + (l2? l2->val:0);
        ListNode *newHead = new ListNode(c%10), *next = l1? l1->next:NULL;
        c /= 10;
        if(next) next->val += c;
        else if(c) next = new ListNode(c);
        newHead->next = addTwoNumbers(l2? l2->next:NULL, next);
        return newHead;
    }*/

};


    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * head = new ListNode();
        ListNode * res = head;
        while(l1 and l2){
            
            int sum = l1->val + l2->val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            ListNode * temp = new ListNode(sum%10);
            head->next = temp;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            ListNode * temp = new ListNode(sum%10);
            head->next = temp;
            head = head->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            ListNode * temp = new ListNode(sum%10);
            head->next = temp;
            head = head->next;
            l2 = l2->next;
        }
        if(carry == 1){
            ListNode * temp = new ListNode(carry);
            head->next = temp;
            head = head->next;
        }
        return res->next;
    }*/