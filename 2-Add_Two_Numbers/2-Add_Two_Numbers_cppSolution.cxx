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
class Solution {
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
