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

// just to not type the type name every time.
typedef pair<int, int> pii; // (max_rob, not_rob)

class Solution {
  // a helper function that returns the best result of the current node
  // together with the best result of the current node that the current node is NOT robbed
  pii rob_helper(TreeNode* node) {
    if (!node) return {0, 0};
    pii left = rob_helper(node->left);
    pii right = rob_helper(node->right);
    // The best result of robbing the current node is the node value
    // plus the best results of the two children with them un-robbed
    // The alarm will be triggered if parent and child are robbed at the same time
    int rob_node = node->val + left.second + right.second;
    // The best result of not robbing the current node is simply the sum of best results
    // of its two children, no matter robbing them or not
    int not_rob = left.first + right.first;
    // Return the better result of robbing or not robbing, together with the non-robbing result
    return {max(rob_node, not_rob), not_rob};
  }
public:
  int rob(TreeNode* root) {
    return rob_helper(root).first;
  }
};
