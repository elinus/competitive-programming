#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int reverse(int x) {
    bool negative = false;
    if (x < 0) {
      negative = true;
      x = -x;
    }
    long long int rev = 0;
    while (x) {
      rev = 10 * rev + x % 10;
      x /= 10;
    }
    if (negative && -rev < INT_MIN)
      return 0;
    else if (rev > INT_MAX)
      return 0;
    else
      negative ? -rev : rev;
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
  /* Code */

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
