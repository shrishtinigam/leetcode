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

/*
Method - 1 Divide and Conquer

*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        if(k == 1)
            return lists[0];
        ListNode *head;
        while(lists.size() != 1){
            ListNode* l1 = lists[0];
            ListNode* l2 = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(mergeTwoLists(l1, l2));
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        while(list1 != NULL and list2 != NULL){
            if(list1->val <= list2->val){
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 != NULL){
            head->next = list1;
        }
        if(list2 != NULL){
            head->next = list2;
        }
        return temp->next;
    }
};