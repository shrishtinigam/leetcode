# Last updated: 10/31/2026, 4:24:04 AM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6
7class Solution:
8    def reverseList(self, head: ListNode | None) -> ListNode | None:
9        if head == None or head.next == None:
10            return head
11        prev = head
12        cur = head.next
13        prev.next = None
14        
15        while cur != None:
16            head = cur.next
17            cur.next = prev
18            prev = cur
19            cur = head
20        
21        return prev