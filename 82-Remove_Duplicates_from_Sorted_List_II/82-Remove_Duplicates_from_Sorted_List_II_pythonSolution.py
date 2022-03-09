# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(next=head)
    prev, curr = dummy, head
    
    while curr:
      while curr and curr.next and curr.val == curr.next.val:
        value = curr.val
        while curr and curr.val == value:
          curr = curr.next
      
      prev.next = curr
      prev = curr
      if curr:
        curr = curr.next
    
    return dummy.next

class Solution_alternative:
  def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(next=head)
    prev, curr = dummy, head
    
    while curr:
      if curr.next and curr.val == curr.next.val:
        value = curr.val
        while curr.next and curr.next.val == value:
          curr = curr.next
        prev.next = curr.next
      else:
        prev = prev.next
        
      curr = curr.next
    
    return dummy.next
