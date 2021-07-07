#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <typename T> void printVec(const vector<T> &vec) {
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
  map<int, vector<int>> ht_map;

public:
  TreeNode *dfs(queue<pair<int, int>> &q, int d) {
    if (q.front().second == d) {
      TreeNode *root = new TreeNode(q.front().first);
      q.pop();
      root->left = dfs(q, d + 1);
      root->right = dfs(q, d + 1);
      return root;
    }
    return nullptr;
  }

  TreeNode *recoverFromPreorder(const string &S) {
    queue<pair<int, int>> q;
    int height = 0;
    for (int i = 0; i < S.length(); ++i) {
      if (S[i] >= '0' && S[i] <= '9') {
        int value = 0;
        while (S[i] >= '0' && S[i] <= '9') {
          value = value * 10 + S[i] - '0';
          i++;
        }
        // ht_map[height].emplace_back(value);
        q.push({value, height});
        height = 0;
        i--;
      }
      if (S[i] == '-')
        height++;
    }
    return dfs(q, 0);
  }

  void print() {
    for (auto it1 = ht_map.begin(); it1 != ht_map.end(); ++it1) {
      cout << it1->first << " : ";
      for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
        cout << *it2 << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
};

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Solution soln1;
  string S1 = "1-2--3--4-5--6--7";
  soln1.recoverFromPreorder(S1);
  soln1.print();

  Solution soln2;
  string S2 = "1-2--3---4-5--6---7";
  soln2.recoverFromPreorder(S2);
  soln2.print();

  Solution soln3;
  string S3 = "1-401--349---90--88";
  soln3.recoverFromPreorder(S3);
  soln3.print();
  return 0;
}
