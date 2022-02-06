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
  int sumNodes(TreeNode* node, int& tilt) {
    if (!node) return 0;
    int leftSum = sumNodes(node->left, tilt);
    int rightSum = sumNodes(node->right, tilt);
    tilt += abs(leftSum - rightSum);
    return leftSum + rightSum + node->val;
  }
public:
  int findTilt(TreeNode* root) {
    int result = 0;
    sumNodes(root, result);
    return result;
  }
};
