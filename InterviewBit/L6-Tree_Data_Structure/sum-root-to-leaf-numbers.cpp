#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sum(TreeNode *root, int total) {
  if (!root)
    return 0;

  total = ((total * 10) % 1003 + root->val) % 1003;
  if (!root->left && !root->right)
    return total;
  return (sum(root->left, total) % 1003 + sum(root->right, total) % 1003) %
         1003;
}

int sumNumbers(TreeNode *A) { return sum(A, 0); }