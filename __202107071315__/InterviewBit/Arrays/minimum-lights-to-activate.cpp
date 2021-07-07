#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int solve(vector<int> &A, int B);
};

int Solution::solve(vector<int> &A, int B) {
  int n = A.size();
  int curr = 0;
  int count = 0;
  while (curr < n) {
    int next = curr + B - 1;
    int ind = next;
    int prev = curr - B + 1;
    if (prev < 0)
      prev = 0;
    while (ind >= prev) {
      if (A[ind])
        break;
      ind--;
    }
    if (ind >= prev) {
      count++;
      curr = ind + B;
    } else
      return -1;
  }
  return count;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> A1 = {0, 0, 1, 1, 1, 0, 0, 1};
  int B = 3;
  print(A1);
  cout << soln.solve(A1, B) << "\n";

  vector<int> A2 = {0, 0, 0, 1, 0};
  print(A2);
  cout << soln.solve(A2, B) << "\n";

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
