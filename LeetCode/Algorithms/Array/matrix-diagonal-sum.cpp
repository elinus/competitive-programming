#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int n = mat.size();
    if (n == 1)
      return mat[0][0];
    int sum = 0;
    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
      sum += (mat[i][i] + mat[i][j]);
    }
    int odd = n % 2;
    if (odd)
      sum -= mat[n/2][n/2];
    return sum;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  cout << soln.diagonalSum(mat1) << "\n";
  vector<vector<int>> mat2 = {
      {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  cout << soln.diagonalSum(mat2) << "\n";
  vector<vector<int>> mat3 = {{5}};
  cout << soln.diagonalSum(mat3) << "\n";
  vector<vector<int>> mat4 = {{1, 2}, {3, 4}};
  cout << soln.diagonalSum(mat4) << "\n";

  return 0;
}
