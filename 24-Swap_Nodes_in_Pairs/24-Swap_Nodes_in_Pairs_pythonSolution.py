# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution_recursive:
  def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
      return head
    child = head.next
    head.next = self.swapPairs(child.next)
    child.next = head
    return child

class Solution_iterative:
  def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(next=head)
    prev = dummy
    while head and head.next:
      prev.next = head.next
      head.next = head.next.next
      prev.next.next = head
      
      prev = head
      head = head.next
    return dummy.next
