# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    
    prev = curr = ListNode()
    q = [(l.val, i) for i, l in enumerate(lists) if l]
    heapq.heapify(q)
    
    while q:
      v, i = heapq.heappop(q)
      curr.next = lists[i]
      node = lists[i] = lists[i].next
      if node and q:
        heapq.heappush(q, (node.val, i))
      curr = curr.next
      
    return prev.next
