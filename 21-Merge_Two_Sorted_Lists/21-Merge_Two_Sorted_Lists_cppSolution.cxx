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
class Solution_iteration {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // create a dummy head to record the start of the merged list
    ListNode* dummyHead = new ListNode();
    // the current end of merged list
    ListNode* curr = dummyHead;
    // we need to compare until we exhaust one of the list
    while (list1 && list2) {
      // we assume list1->val is smaller, if not, swap them
      if (list1->val > list2->val) {
        swap(list1, list2);
      }
      // here list1 is guaranteed to be smaller than list2
      // append list1 to the merged list
      // move both curr and list1 to prepare for the next iteration
      curr->next = list1;
      curr = list1;
      list1 = list1->next;
    }
    // we exhausted one of the lists
    // append the remainder of the other list to the merged list
    if (list1) curr->next = list1;
    else if (list2) curr->next = list2;
    // return the start of the merged list
    return dummyHead->next;
  }
};

class Solution_recursion {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->val > list2->val) {
      swap(list1, list2);
    }
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};
