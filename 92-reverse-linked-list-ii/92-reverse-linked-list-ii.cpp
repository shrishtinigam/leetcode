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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode * leftprev = dummy;
        ListNode * cur = head;
        for(int i = 0; i < left-1; i++){
            leftprev = cur;
            cur = cur->next;
        }
        
        ListNode * prev = NULL;
        for(int i = 0; i < (right - left + 1); i++){
            ListNode * temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        leftprev->next->next = cur;
        leftprev->next = prev;
        
        ListNode* temp2 = dummy->next;
        delete dummy;
        return temp2;
    }
};

/*
        if(head->next == NULL)
            return head;
        ListNode * cur = head;
        left--;        
        left--;
        for(int i = 0; i < left; i++){
            cur = cur->next;
        }
        cout << cur->val<<"\n";
        
        int count = left;
        if(left+2 == 1)
            count = 0;
        ListNode * ptr = cur;
        ListNode * ptr2 = cur->next;
        ListNode* prev = NULL; 
        ListNode * temp;
        while(count < right){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            count++;
        }
        cout<<prev->val<<"\n";        
        cout<<ptr->val<<"\n";
        cout<<ptr2->val<<"\n";

        /*
        //ListNode * x = ptr->next;
        ptr->next = prev;
        ptr2->next = cur;
        return head;
*/