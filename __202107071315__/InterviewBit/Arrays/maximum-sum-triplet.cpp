#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int solve(vector<int> &A);
};

int Solution::solve(vector<int> &A) {
  int triplet_sum = 0;
  int n = A.size();
  for (int i = 1; i < n - 1; ++i) {
    int max1 = 0, max2 = 0;

    for (int j = 0; j < i; ++j)
      if (A[j] < A[i])
        max1 = max(max1, A[j]);

    for (int j = i + 1; j < n; ++j)
      if (A[j] > A[i])
        max2 = max(max2, A[j]);

    if (max1 && max2)
      triplet_sum = max(triplet_sum, max1 + A[i] + max2);
  }
  return triplet_sum;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> A1 = {2, 5, 3, 1, 4, 9};
  vector<int> A2 = {1, 2, 3};
  cout << soln.solve(A1) << "\n";
  cout << soln.solve(A2) << "\n";

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
