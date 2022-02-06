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
// a small struct to hold information for each node
struct nodeInfo {
  // data members
  bool valid;
  int max_val, min_val, max_size;
  // constructor
  nodeInfo(bool v, int min_v, int max_v, int size)
    : valid(v), min_val(min_v), max_val(max_v), max_size(size) {}
};

class Solution {
public:
  int largestBSTSubtree(TreeNode* root) {
    return isBSTSubtree(root).max_size;
  }
  // function to determine the BST validness of a given node
  // return: {isValid, min_val, max_val, max BST subtree size}
  nodeInfo isBSTSubtree(TreeNode* node) {
    // base case: null node should be returned as valid BST with size 0
    // min_val and max_val are chosen to make sure parent nodes satisfy BST requirement automatically
    if (!node) return nodeInfo(true, INT_MAX, INT_MIN, 0);
    
    // compute info for left and right subtree
    nodeInfo left_info = isBSTSubtree(node->left);
    nodeInfo right_info = isBSTSubtree(node->right);
    
    // if either left or right subtree is not BST, node is not going to be a BST
    // if node value is larger than right min or smaller than left max, it is not a BST also
    // return invalid status, min/max_val such that evaluation will always fail for parent nodes
    // return the max size from left/right subtrees that was determined a valid BST
    if (!left_info.valid || !right_info.valid || node->val >= right_info.min_val || node->val <= left_info.max_val)
      return nodeInfo(false, INT_MIN, INT_MAX, max(left_info.max_size, right_info.max_size));
    
    // here we have a valid BST
    // in general min/max values are from left/right subtrees
    // but in case the child node is null, we need to put the current node value in.
    int min_value = min(left_info.min_val, node->val);
    int max_value = max(right_info.max_val, node->val);
    
    // return valid status, computed min/max values, total size of tree at node
    return nodeInfo(1, min_value, max_value, left_info.max_size + right_info.max_size + 1);
  }
};
