#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int solve(TreeNode *A) {
  if (!A)
    return 0;
  int max_sum = 0, sum = 0;
  queue<TreeNode *> q;
  q.push(A);
  q.push(nullptr);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      sum += node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    } else {
      if (!q.empty())
        q.push(nullptr);
      max_sum = max(max_sum, sum);
      sum = 0;
    }
  }
  return max_sum;
}
