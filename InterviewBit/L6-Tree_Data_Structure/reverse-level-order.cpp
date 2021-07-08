#include <iostream>
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
  vector<int> ans;
  if (!A)
    return ans;
  stack<vector<int>> st;
  queue<TreeNode *> q;
  q.push(A);
  q.push(nullptr);
  vector<int> v;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      v.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    } else {
      if (!q.empty())
        q.push(nullptr);
      st.push(move(v));
    }
  }
  while (!st.empty()) {
    auto var = st.top();
    st.pop();
    for (auto it = var.begin(); it != var.end(); ++it) {
      ans.push_back(*it);
    }
  }
  return ans;
}