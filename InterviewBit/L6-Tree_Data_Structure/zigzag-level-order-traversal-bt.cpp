#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *A) {
  vector<vector<int>> result;
  if (!A)
    return result;
  stack<TreeNode *> st1, st2;
  st1.push(A);
  while (!st1.empty() || !st2.empty()) {
    vector<int> v1;
    while (!st1.empty()) {
      TreeNode *node = st1.top();
      st1.pop();
      v1.push_back(node->val);
      if (node->left)
        st2.push(node->left);
      if (node->right)
        st2.push(node->right);
    }
    if (!v1.empty())
      result.push_back(move(v1));

    vector<int> v2;
    while (!st2.empty()) {
      TreeNode *node = st2.top();
      st2.pop();
      v2.push_back(node->val);
      if (node->right)
        st1.push(node->right);
      if (node->left)
        st1.push(node->left);
    }
    if (!v2.empty())
      result.push_back(move(v2));
  }
  return result;
}
