// Last updated: 8/30/2025, 8:18:29 PM
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
    /*
    ListNode* middleNode(ListNode* head) {
       int cnt = 0;
       ListNode *node = head;
       while(node){
           cnt++;
           node = node->next;
       }
       int mid = cnt/2;
       for(int i = 0; i < mid; i++){
           head = head->next;
       }
       return head;
    }*/

    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};

/*
 int count = 0;
        ListNode* ptr = head;
        while(ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        int mid = count/2;
        ptr = head;
        while(mid--)
            ptr = ptr->next;
        return ptr;
*/