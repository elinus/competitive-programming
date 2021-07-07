#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int numberOfMatches(int n) {
    int match = 0;
    while (n) {
      match += (n / 2);
      if (n == 1)
        break;
      if (n % 2) { // odd
        n = n / 2 + 1;
      } else {
        n /= 2;
      }
    }
    return match;
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
  cout << soln.numberOfMatches(7) << "\n";
  cout << soln.numberOfMatches(14) << "\n";
  cout << soln.numberOfMatches(0) << "\n";
  cout << soln.numberOfMatches(1) << "\n";
  cout << soln.numberOfMatches(10) << "\n";
  cout << soln.numberOfMatches(5) << "\n";
  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
