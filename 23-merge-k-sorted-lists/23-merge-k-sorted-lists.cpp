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
    struct heapNode{
        ListNode * curr;
        int idx;
        heapNode(ListNode*a, int b){
            curr = a;
            idx = b;
        }
    };
    struct compare{
        bool operator()(heapNode a, heapNode b){
            return a.curr->val > b.curr->val; // greater function
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        priority_queue<heapNode, vector<heapNode>, compare> heap;
        vector <ListNode*> ptr(k);
        for(int i = 0; i < k; i++){
            ptr[i] = lists[i];
            if(lists[i] != NULL)
                heap.push(heapNode(lists[i],i));
        }
        
        if(heap.empty())
            return NULL;
        
        ListNode * head, *tail;
        head = tail = heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        
        ptr[idx] = ptr[idx]->next;
        if(ptr[idx])
            heap.push(heapNode(ptr[idx], idx));
        
        while(!heap.empty()){
            ListNode * temp = heap.top().curr;
            idx = heap.top().idx;
            heap.pop();
            
            tail->next = temp;
            tail = tail->next;
            ptr[idx] = ptr[idx]->next;
            
            if(ptr[idx])
                heap.push(heapNode(ptr[idx], idx));
        }
        
        return head;
    }
};

/*
Method - 1 Divide and Conquer

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
*/
