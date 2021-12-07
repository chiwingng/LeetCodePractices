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
  int getHeight(TreeNode* node, vector<vector<int>>& result) {
    if (!node) return -1;
    int curr_height = max(getHeight(node->left, result), getHeight(node->right, result)) + 1;
    if (curr_height == result.size()) result.emplace_back();
    result[curr_height].push_back(node->val);
    return curr_height;
  }
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> result;
    getHeight(root, result);
    return result;
  }
};
