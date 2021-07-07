#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat[0].size();
    int max_ = rows > cols ? rows : cols;

    // for (int i = 0; i < rows; i++) {
    //     print(mat[i]);
    // }
    // cout << "\n";
    
    vector<int> tvec(max_);
    int ti = 0;
    for (int r = rows - 2; r > 0; r--) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if ((i - j) == r) {
            tvec[ti++] = mat[i][j];
          }
        }
      }
      sort(tvec.begin(), tvec.begin() + ti);
      int si = 0;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if ((i - j) == r) {
            mat[i][j] = tvec[si++];
          }
          if (si == ti)
            break;
        }
        if (si == ti)
          break;
      }
      ti = 0;
    }

    for (int c = 0; c < cols - 1; c++) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if ((j - i) == c) {
            tvec[ti++] = mat[i][j];
          }
        }
      }
      sort(tvec.begin(), tvec.begin() + ti);
      int si = 0;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if ((j - i) == c) {
            mat[i][j] = tvec[si++];
          }
          if (si == ti)
            break;
        }
        if (si == ti)
          break;
      }
      ti = 0;
    }

    // for (int i = 0; i < rows; i++) {
    //     print(mat[i]);
    // }
    // cout << "\n";

    return mat;
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
  vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
  soln.diagonalSort(mat);

  mat = {{0}};
  soln.diagonalSort(mat);

  mat = {{4, 3}, {2, 1}};
  soln.diagonalSort(mat);
  
  mat = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  soln.diagonalSort(mat);

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
