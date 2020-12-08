#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int coverPoints(vector<int> &A, vector<int> &B);
};

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
  int distance = 0;
  int n = A.size();
  for (int i = 0; i < n - 1; i++) {
    int a_dist = abs(A[i + 1] - A[i]);
    int b_dist = abs(B[i + 1] - B[i]);
    distance += (a_dist > b_dist) ? a_dist : b_dist;
  }
  return distance;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  /* Code */

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
