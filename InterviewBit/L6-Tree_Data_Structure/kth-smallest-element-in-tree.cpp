#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct TreeNode treenode;

void inorder(TreeNode *root, const int k, int &count, int &ans) {
  if (root) {
    inorder(root->left, k, count, ans);
    count++;
    if (count == k) {
      ans = root->val;
      return;
    }
    inorder(root->right, k, count, ans);
  }
}

int kthsmallest(treenode *A, int B) {
  int ans = -1;
  int count = 0;
  inorder(A, B, count, ans);
  return ans;
}
