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
class Solution_iterative {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    
    ListNode* prev = dummy;
    while (head && head->next) {
      prev->next = head->next;
      head->next = head->next->next;
      prev->next->next = head;
      
      prev = head;
      head = head->next;
    }
    
    return dummy->next;
  }
};

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
class Solution_recursive {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* child = head->next;
    head->next = swapPairs(child->next);
    child->next = head;
    return child;
  }
};
