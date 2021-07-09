#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> solve(TreeNode *A) {
  if (!A)
    return {};

  map<int, int> ht;
  queue<TreeNode *> q;
  int level = 0;
  q.push(A);
  q.push(nullptr);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      ht[level] = node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    } else {
      if (!q.empty())
        q.push(nullptr);
      level++;
    }
  }

  vector<int> res;
  for (auto it = ht.begin(); it != ht.end(); ++it) {
    res.push_back(it->second);
  }
  return res;
}