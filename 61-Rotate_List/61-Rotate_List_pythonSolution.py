# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if not head or not head.next or k == 0:
      return head
    curr = head
    length = 1
    while curr.next:
      length += 1
      curr = curr.next
    k %= length
    if k == 0:
      return head
    curr.next = head
    k = length - k - 1
    curr = head
    while k > 0:
      k -= 1
      curr = curr.next
    head = curr.next
    curr.next = None
    return head
