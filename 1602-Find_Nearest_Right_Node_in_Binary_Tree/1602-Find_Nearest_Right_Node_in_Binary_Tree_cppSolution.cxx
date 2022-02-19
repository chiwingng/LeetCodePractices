#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    queue<TreeNode*> tree_q;
    bool found_u = false;
    tree_q.push(root);
    // loop until the end of the tree
    while (!tree_q.empty()) {
      // traverse within the current level
      for (int i = tree_q.size(); i > 0; i--) {
        // if we found u already, the current node is what we want ;)
        if (found_u) return tree_q.front();
        // if not, extract the current node
        TreeNode* node = tree_q.front();
        // check if it's u
        found_u = (node == u);
        // push its left/right children into the queue if exist
        if (node->left) tree_q.push(node->left);
        if (node->right) tree_q.push(node->right);
        // pop the current node out of the queue.
        tree_q.pop();        
      }
      // if we found u and reach here, it's the last node of the level
      // return null
      if (found_u) return nullptr;
    }
    // we don't find anything matching u, return null
    return nullptr;
  }
};
