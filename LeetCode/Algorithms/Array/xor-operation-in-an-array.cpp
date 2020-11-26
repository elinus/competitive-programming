#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int xorOperation(int n, int start) {
    vector<int> v(n);
    int x_o_r = 0;
    for (int i = 0; i < n; i++) {
      v[i] = start + 2 * i;
      x_o_r ^= v[i];
    }
    return x_o_r;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  cout << soln.xorOperation(5, 0) << "\n";
  cout << soln.xorOperation(4, 3) << "\n";
  cout << soln.xorOperation(1, 7) << "\n";
  cout << soln.xorOperation(10, 5) << "\n";

  return 0;
}
