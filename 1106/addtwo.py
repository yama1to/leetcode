# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum=0
        plus = 0
        returnNode = cur = ListNode(0)
        while l1 or l2  or plus :
            if l1:
                sum += l1.val
                l1 = l1.next

            if l2:
                sum += l2.val
                l2 = l2.next


            sum = sum + plus
            plus = sum // 10
            remain = sum % 10

            cur.next = ListNode(remain)
            cur = cur.next 
            sum=0

        return returnNode.next


