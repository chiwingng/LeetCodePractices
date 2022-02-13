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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = root;
    while (node) {
      if (val > node->val) {
        // insert value should go to the right
        if (!node->right) {
          // if there're no node on the right, insert it there and we are done
          node->right = new TreeNode(val);
          return root;
        }
        // go to the right node and repeat
        else node = node->right;
      }
      else {
        // insert value should go to the left
        if (!node->left) {
          // if there're no node on the left, insert it there and we are done
          node->left = new TreeNode(val);
          return root;
        }
        // go to the left node and repeat
        else node = node->left;
      }
    }
    // we end up here if root is null. create a new node as root and return.
    return new TreeNode(val);
  }
};
