#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *invertTree(TreeNode *A) {
  if (A == nullptr)
    return A;
  A->left = invertTree(A->left);
  A->right = invertTree(A->right);
  swap(A->left, A->right);
  return A;
}
