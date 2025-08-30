// Last updated: 8/30/2025, 8:19:32 PM
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
    ListNode* reverseList(ListNode* head) {
        /*
        ListNode *next, *prev = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;*/
        if(!head or !(head->next)){
            return head;
        }
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};
/*
ListNode* reverseList(ListNode* head) {
        if (!head or !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
*/
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};*/