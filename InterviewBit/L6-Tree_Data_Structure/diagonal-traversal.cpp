#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traverse_util(TreeNode *root, int key, map<int, vector<int>> &ht) {
  if (root) {
    ht[key].push_back(root->val);
    traverse_util(root->left, key + 1, ht);
    traverse_util(root->right, key, ht);
  }
}

vector<int> solve(TreeNode *A) {
  vector<int> result;
  map<int, vector<int>> ht;
  traverse_util(A, 0, ht);
  for (auto i = ht.begin(); i != ht.end(); ++i) {
    for (auto j = i->second.begin(); j != i->second.end(); ++j) {
      result.push_back(*j);
    }
  }
  return result;
}
