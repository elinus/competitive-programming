#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    if (A.empty())
      return A;
    int rows = A.size(), cols = A[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols / 2; j++) {
        swap(A[i][j], A[i][cols - j - 1]);
        A[i][j] = 1 - A[i][j];
        A[i][cols - j - 1] = 1 - A[i][cols - j - 1];
      }
      if (cols%2) A[i][cols/2] = 1 - A[i][cols/2];
    }
    return A;
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
  vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  for (int i = 0; i < A.size(); i++) {
    print(A[i]);
  }
  cout << "\n";
  auto result = soln.flipAndInvertImage(A);
  for (int i = 0; i < result.size(); i++) {
    print(result[i]);
  }

  vector<vector<int>> B = {
      {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  for (int i = 0; i < B.size(); i++) {
    print(B[i]);
  }
  cout << "\n";
  result = soln.flipAndInvertImage(B);
  for (int i = 0; i < result.size(); i++) {
    print(result[i]);
  }

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
