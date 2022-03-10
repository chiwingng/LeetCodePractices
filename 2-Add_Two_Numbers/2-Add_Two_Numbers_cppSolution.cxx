/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution_iterative {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(), *tail = result;
    int increment = 0;
    while (l1 || l2 || increment) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + increment;
      
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      
      increment = sum/10;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    return result->next;
  }
};

class Solution_recursive {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return l1;
    if (!l1) l1 = new ListNode();
    if (!l2) l2 = new ListNode();
    int sum = l1->val + l2->val;
    if (sum > 9) {
      if (l1 && l1->next) l1->next->val++;
      else if (l2 && l2->next) l2->next->val++;
      else l1->next = new ListNode(1);
    }
    return new ListNode(sum % 10, addTwoNumbers(l1->next, l2->next));
  }
};
