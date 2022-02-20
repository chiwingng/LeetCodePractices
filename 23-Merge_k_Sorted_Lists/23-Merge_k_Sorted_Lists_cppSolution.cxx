#include <priority_queue>

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // create lambda for comparing ListNodes
    // priority queue is a max heap, so greater comparison is used to convert it into a min heap
    auto compareNodes = [] (ListNode* n1, ListNode* n2) {
      return n1->val > n2->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compareNodes)> node_q(compareNodes);

    // initialize the PQ
    for (ListNode* l : lists) {
      if (l) node_q.push(l);
    }

    // create a node prev to record the start of the list
    ListNode* prev = new ListNode(), *curr = prev;
    while (!node_q.empty()) {
      // for each node at the front of the queue, append it to the output list
      ListNode *n = node_q.top();
      curr->next = n;
      node_q.pop();
      // push the next node into the PQ to sort again
      // skip the process if we have only one node left in the queue
      if (n->next && !node_q.empty()) node_q.push(n->next);
      curr = n;
    }
    
    return prev->next;
  }
};
