#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>> &indices) {
    vector<vector<int>> matx(n, vector<int>(m, 0));
    for (int i = 0; i < indices.size(); i++) {
      int row = indices[i][0], col = indices[i][1];
      for (int ri = 0; ri < n; ri++) {
        matx[ri][col] += 1;
      }
      for (int ci = 0; ci < m; ci++) {
        matx[row][ci] += 1;
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matx[i][j] % 2)
          count++;
      }
    }
    return count;
  }
};

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  int n1 = 2, m1 = 3;
  vector<vector<int>> indices1 = {{0, 1}, {1, 1}};
  cout << soln.oddCells(n1, m1, indices1) << "\n";

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
