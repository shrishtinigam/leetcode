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
        int carry = 0;
        ListNode * head = new ListNode();
        ListNode * res = head;
        while(l1 and l2){
            
            int sum = l1->val + l2->val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            cout << sum%10 << " ";
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
            cout << sum%10 << " ";
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
            cout << sum%10 << " ";
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
    }
};


/*
ListNode * one = l1, * two = l2;
        int sum = 0, place = 1, carry = 0;
        string result = 0;
        while(one and two){
            sum = one->val + two->val + carry;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            result = (char) (sum % 10) + result;
            one = one->next;
            two = two->next;
        }
        cout <<  stoi(result);
        return l1;
*/