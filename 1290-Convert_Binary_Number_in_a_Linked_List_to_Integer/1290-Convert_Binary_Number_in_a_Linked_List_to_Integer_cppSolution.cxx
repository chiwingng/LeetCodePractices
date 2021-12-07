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
  int getDecimalValue(ListNode* head) {
    int result = head->val;
    while (head->next) {
      // next digit exists
      // multiply prefix by two and add the next digit
      result = (result << 1) | head->next->val;
      // move to next digit
      head = head->next;
    }
    return result;
  }
};
