# Last updated: 10/31/2026, 4:41:05 AM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, x):
4#         self.val = x
5#         self.next = None
6
7class Solution:
8    def hasCycle(self, head: Optional[ListNode]) -> bool:
9        slow = head
10        fast = head
11
12        while fast != None:
13            slow = slow.next
14            fast = fast.next
15            if fast != None:
16                fast = fast.next
17            if slow == fast and slow != None:
18                return True
19        return False