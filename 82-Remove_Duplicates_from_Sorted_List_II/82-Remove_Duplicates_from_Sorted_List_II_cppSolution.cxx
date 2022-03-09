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
public:
  ListNode* deleteDuplicates(ListNode* head) {
    // dummy head for recording the start of list
    ListNode* dummyHead = new ListNode(999, head);
    // node indicating the end of non-duplicated list
    ListNode* curr = dummyHead;
    // node iterating through the list
    ListNode* nextNode = head;
    
    // iterate until the end of list
    while (nextNode) {
      // if the next node is the same as this one
      if (nextNode->next && nextNode->val == nextNode->next->val) {
        // iterate until the end of same-valued nodes
        while (nextNode->next && nextNode->val == nextNode->next->val) {
          nextNode = nextNode->next;
        }
        // attach the next non-identical node to curr
        curr->next = nextNode->next;
      }
      else {
        // nextNode is not duplicated, we are save to advance curr
        curr = curr->next;
      }
      // advance nextNode to iterate through the list
      nextNode = nextNode->next;
    }
    // return the actual head of the resulting list
    return dummyHead->next;
  }
};

class Solution_alternative {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummyHead = new ListNode(999, head);
    ListNode* curr = dummyHead;
    ListNode* nextNode = curr->next;
    while (nextNode) {
      // check for all concatenated duplicating nodes
      while (nextNode && nextNode->next && nextNode->val == nextNode->next->val) {
        int start = nextNode->val;
        // skip all nodes with same val
        while (nextNode && nextNode->val == start) nextNode = nextNode->next;
      }
      // end of duplicating nodes
      curr->next = nextNode;
      // advance if there exists
      curr = nextNode;
      if (nextNode) nextNode = nextNode->next;
    }
    return dummyHead->next;
  }
};
