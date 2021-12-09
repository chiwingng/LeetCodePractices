/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
  // this function serves as a helper computing 3 things at the same time
  // 1. it returns the weighted sum of all the integers ni contains
  // 2. it adds to total_sum all the unweighted integers ni contains
  // 3. it compares the current depth of NI to max_depth and updates if necessary
  int getSum(const NestedInteger& ni, int& total_sum, int& max_depth, int curr_depth) {
    max_depth = max(curr_depth, max_depth);
    int weighted_sum = 0;
    if (ni.isInteger()) {
      total_sum += ni.getInteger();
      weighted_sum = curr_depth * ni.getInteger();
    }
    else {
      for (const NestedInteger& nested : ni.getList()) {
        weighted_sum += getSum(nested, total_sum, max_depth, curr_depth + 1);
      }
    }
    return weighted_sum;
  }
public:
  // The formula can be broken down into 2 parts:
  // \Sum(v_i * (max_depth - d_i + 1)) where v_i is the integer value, d_i is the depth of integer
  // = \Sum(v_i) * (max_depth + 1) - \Sum(v_i * d_i)
  // = total_sum * (max_depth + 1) - weighted_sum
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    // here result stores the second part of the formula: -weighted_sum
    int result = 0, max_depth = 1, total_sum = 0;
    for (const NestedInteger& ni : nestedList) {
      result -= getSum(ni, total_sum, max_depth, 1);
    }
    // here we add the first part of the formula to our result and return
    return result + (max_depth + 1) * total_sum;
  }
};
