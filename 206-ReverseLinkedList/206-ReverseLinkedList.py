# Last updated: 10/31/2026, 4:25:31 AM
1class Solution:
2    def reverseList(self, head: ListNode | None) -> ListNode | None:
3        if head == None or head.next == None:
4            return head
5        prev = head
6        cur = head.next
7        prev.next = None
8
9        while cur != None:
10            next_node = cur.next
11            cur.next = prev
12            prev = cur
13            cur = next_node
14
15        return prev