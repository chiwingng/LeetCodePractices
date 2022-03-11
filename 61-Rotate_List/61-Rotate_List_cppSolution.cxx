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
  ListNode* rotateRight(ListNode* head, int k) {
    // Simple checks
    if (!head || !head->next || k == 0) return head;
    // Find the tail and count the length at the same time
    ListNode *curr = head;
    int length = 1;
    while (curr->next) {
      length++;
      curr = curr->next;
    }
    // Find the net number of rotations needed
    k %= length;
    // If we don't need to rotate at all, return the original list
    if (k == 0) return head;
    // Attach the end of the list to the head
    curr->next = head;
    // Find the end of the new list
    k = length - k;
    curr = head;
    while (--k) {
      curr = curr->next;
    }
    // The next of new end is the new head
    head = curr->next;
    // Break the cycle
    curr->next = nullptr;
    // Job done.
    return head;
  }
};
